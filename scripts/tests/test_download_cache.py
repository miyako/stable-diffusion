"""Execute the shipped helper; these tests do not execute the 4D HTTP callbacks."""

import copy
from contextlib import contextmanager
import hashlib
import http.client
from http.server import ThreadingHTTPServer
import json
import os
from pathlib import Path
import subprocess
import tempfile
import threading
import unittest
import urllib.error
import urllib.request

from download_fixture import CONTENT, FixtureHandler

ROOT = Path(__file__).resolve().parents[2]
DEFAULT = ROOT / ".build/package" / ("Windows/sd-cache.exe" if os.name == "nt" else "macOS/sd-cache")
EXECUTABLE = Path(os.environ.get("SD_CACHE_EXECUTABLE", DEFAULT)).resolve()


@contextmanager
def fixture_server():
    server = ThreadingHTTPServer(("127.0.0.1", 0), FixtureHandler)
    thread = threading.Thread(target=server.serve_forever, daemon=True)
    thread.start()
    try:
        yield f"http://127.0.0.1:{server.server_port}"
    finally:
        server.shutdown()
        server.server_close()
        thread.join(timeout=5)


@unittest.skipUnless(EXECUTABLE.is_file(), "Build sd-cache or set SD_CACHE_EXECUTABLE")
class DownloadCacheTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory(prefix="sd-cache-test-")
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name).resolve()
        self.destination = self.root / "model.bin"
        self.content = b"fixture model\n"
        self.descriptor = {
            "repo": "owner/model", "destination": str(self.destination),
            "is_file": True, "paths": ["model.bin"], "domain": "image",
        }
        self.metadata = {
            "sha": "a" * 40,
            "siblings": [{
                "rfilename": "model.bin", "size": len(self.content), "blobId": "b" * 40,
                "lfs": {"size": len(self.content), "sha256": hashlib.sha256(self.content).hexdigest()},
                "xetHash": "c" * 64,
            }],
        }

    def call(self, operation, success=True, **kwargs):
        result = subprocess.run(
            [str(EXECUTABLE)], input=json.dumps({"operation": operation, **kwargs}),
            text=True, capture_output=True, timeout=15,
        )
        response = json.loads(result.stdout)
        self.assertEqual(response["success"], success, response)
        self.assertEqual(result.returncode, 0 if success else 1, response)
        return response

    def plan(self, metadata=None, descriptor=None):
        return self.call("plan", descriptor=descriptor or self.descriptor,
                         metadata=self.metadata if metadata is None else metadata)["plan"]

    def test_lfs_content_identity_and_pinned_revision_not_pointer_or_xet(self):
        plan = self.plan()
        file = plan["files"][0]
        self.assertEqual(file["algorithm"], "sha256")
        self.assertEqual(file["digest"], hashlib.sha256(self.content).hexdigest())
        self.assertIn("/resolve/" + "a" * 40 + "/model.bin", file["url"])
        self.destination.write_bytes(self.content)
        self.assertTrue(self.call("verify", file=file)["valid"])

    def test_git_blob_header_is_part_of_sha1(self):
        metadata = copy.deepcopy(self.metadata)
        entry = metadata["siblings"][0]
        entry.pop("lfs")
        entry["blobId"] = hashlib.sha1(b"blob " + str(len(self.content)).encode() + b"\0" + self.content).hexdigest()
        file = self.plan(metadata)["files"][0]
        self.destination.write_bytes(self.content)
        self.assertTrue(self.call("verify", file=file)["valid"])
        file["digest"] = hashlib.sha1(self.content).hexdigest()
        self.assertFalse(self.call("verify", file=file)["valid"])

    def test_metadata_can_be_raw_json_but_invalid_json_fails(self):
        self.assertEqual(self.plan(json.dumps(self.metadata))["metadata"], self.metadata)
        self.call("plan", success=False, descriptor=self.descriptor, metadata="<html>bad gateway</html>")

    def test_empty_missing_malformed_and_unauthoritative_metadata_fail(self):
        variants = [None, [], {}, {"sha": "a" * 40, "siblings": []}]
        for field in ("size", "blobId"):
            metadata = copy.deepcopy(self.metadata)
            metadata["siblings"][0].pop("lfs")
            metadata["siblings"][0].pop(field)
            variants.append(metadata)
        for changed in (
            {"size": -1}, {"size": "13"}, {"lfs": {"size": 1, "sha256": "a" * 64}},
            {"lfs": {"size": len(self.content), "sha256": "opaque-etag"}},
            {"rfilename": "not-the-model.bin"},
        ):
            metadata = copy.deepcopy(self.metadata)
            metadata["siblings"][0].update(changed)
            variants.append(metadata)
        for metadata in variants:
            with self.subTest(metadata=metadata):
                self.call("plan", success=False, descriptor=self.descriptor, metadata=metadata)

    def test_unsafe_duplicate_paths_and_symlink_escape_are_rejected(self):
        for path in ("../escape", "/absolute", "sub/../../escape", "C:/file", "a\\b", "a//b",
                     "a/./b", "CON", "a.", "a ", "a\0b"):
            descriptor = copy.deepcopy(self.descriptor)
            descriptor["paths"] = [path]
            with self.subTest(path=path):
                self.call("descriptor", success=False, descriptor=descriptor)
        metadata = copy.deepcopy(self.metadata)
        metadata["siblings"] *= 2
        self.call("plan", success=False, descriptor=self.descriptor, metadata=metadata)
        if os.name != "nt":
            outside = self.root / "outside"
            outside.mkdir()
            root = self.root / "cache"
            root.mkdir()
            (root / "nested").symlink_to(outside, target_is_directory=True)
            descriptor = {**self.descriptor, "is_file": False, "destination": str(root), "paths": []}
            metadata = copy.deepcopy(self.metadata)
            metadata["siblings"][0]["rfilename"] = "nested/model.bin"
            self.call("plan", success=False, descriptor=descriptor, metadata=metadata)

    def test_missing_truncated_oversized_and_same_size_corrupt_cache(self):
        file = self.plan()["files"][0]
        self.assertFalse(self.call("verify", file=file)["valid"])
        for content in (self.content[:-1], self.content + b"x", b"x" * len(self.content)):
            self.destination.write_bytes(content)
            self.assertFalse(self.call("verify", file=file)["valid"])

    def test_failed_or_partial_download_never_replaces_good_cache(self):
        file = self.plan()["files"][0]
        original = b"previous good model"
        self.destination.write_bytes(original)
        candidate = self.root / ".sd-part-fixture"
        for content in (self.content[:-1], b"x" * len(self.content)):
            candidate.write_bytes(content)
            self.call("commit", success=False, file=file, candidate=str(candidate))
            self.assertEqual(self.destination.read_bytes(), original)
        candidate.write_bytes(self.content)
        self.call("commit", file=file, candidate=str(candidate))
        self.assertFalse(candidate.exists())
        self.assertEqual(self.destination.read_bytes(), self.content)

    def test_promotion_requires_same_directory_and_rejects_symlink_targets(self):
        file = self.plan()["files"][0]
        other = self.root / "other"
        other.mkdir()
        candidate = other / ".sd-part-fixture"
        candidate.write_bytes(self.content)
        self.call("commit", success=False, file=file, candidate=str(candidate))
        if os.name != "nt":
            target = self.root / "other-file"
            target.write_bytes(self.content)
            self.destination.symlink_to(target)
            self.call("verify", success=False, file=file)

    def test_verified_receipt_enables_offline_and_detects_later_corruption(self):
        plan = self.plan()
        self.destination.write_bytes(self.content)
        self.call("save-plan", plan=plan)
        restored = self.call("load-plan", descriptor=self.descriptor)["plan"]
        self.assertEqual(plan, restored)
        self.destination.write_bytes(b"x" * len(self.content))
        self.call("load-plan", success=False, descriptor=self.descriptor)
        self.destination.unlink()
        self.call("load-plan", success=False, descriptor=self.descriptor)

    def test_no_receipt_wrong_identity_and_malformed_receipt_fail_offline(self):
        self.destination.write_bytes(self.content)
        self.call("load-plan", success=False, descriptor=self.descriptor)
        plan = self.plan()
        self.call("save-plan", plan=plan)
        changed = {**self.descriptor, "repo": "owner/another-model"}
        self.call("load-plan", success=False, descriptor=changed)
        receipt = next(self.root.glob(".sd-download-*.json"))
        receipt.write_text("{bad json")
        self.call("load-plan", success=False, descriptor=self.descriptor)

    def test_receipt_not_written_for_incomplete_plan_or_tampered_files(self):
        plan = self.plan()
        self.call("save-plan", success=False, plan=plan)
        self.destination.write_bytes(self.content)
        plan["files"][0]["digest"] = "0" * 64
        self.call("save-plan", success=False, plan=plan)
        self.assertFalse(list(self.root.glob(".sd-download-*.json")))

    def test_folder_selection_requires_every_requested_file(self):
        descriptor = {**self.descriptor, "is_file": False, "destination": str(self.root / "folder"),
                      "paths": ["model.bin", "missing.bin"]}
        self.call("plan", success=False, descriptor=descriptor, metadata=self.metadata)
        descriptor["paths"] = ["model.bin"]
        plan = self.plan(descriptor=descriptor)
        self.assertEqual(Path(plan["files"][0]["destination"]), self.root / "folder/model.bin")

    def test_auth_is_not_forwarded_to_signed_cdn_redirect(self):
        result = self.call("redirect", location="https://cdn.example.test/model?signature=opaque")
        self.assertFalse(result["authorize"])
        self.assertTrue(self.call("redirect", location="/api/resolve-cache/model")["authorize"])
        relative = self.call("redirect", location="/model?signature=opaque",
                             base="https://cdn.example.test/old-path")
        self.assertEqual(relative["url"], "https://cdn.example.test/model?signature=opaque")
        self.assertFalse(relative["authorize"])
        for location in ("http://example.test/model", "//example.test/path", "https://user@evil.test/path",
                         "https://huggingface.co.evil.test@evil.test/a", "https://host.test\\evil/path",
                         "https://host.test/path\r\nAuthorization: secret"):
            with self.subTest(location=location):
                self.call("redirect", success=False, location=location)

    def test_real_http_bytes_are_verified_before_atomic_promotion(self):
        """Uses real HTTP and production sd-cache, not the 4D networking runtime."""
        file = self.plan()["files"][0]
        candidate = self.root / ".sd-part-http"
        with fixture_server() as base:
            for case in ("success", "no-length", "corrupt", "truncated"):
                with self.subTest(case=case):
                    self.destination.write_bytes(b"previous good model")
                    with urllib.request.urlopen(base + "/download/" + case, timeout=5) as response:
                        try:
                            content = response.read()
                        except http.client.IncompleteRead as error:
                            content = error.partial
                    candidate.write_bytes(content)
                    valid = case in ("success", "no-length")
                    self.call("commit", success=valid, file=file, candidate=str(candidate))
                    self.assertEqual(self.destination.read_bytes(), CONTENT if valid else b"previous good model")


class HTTPFixtureTests(unittest.TestCase):
    def test_http_and_transport_failure_cases_are_real(self):
        """Checks fixture contracts only; 4D callback assertions live in tests/4d."""
        with fixture_server() as base:
            for status in (401, 403, 404, 429, 500, 503):
                for family, case in (("metadata", f"metadata-http-{status}"),
                                     ("download", f"http-{status}")):
                    with self.subTest(family=family, status=status):
                        with self.assertRaises(urllib.error.HTTPError) as failure:
                            urllib.request.urlopen(f"{base}/{family}/{case}", timeout=5)
                        self.assertEqual(failure.exception.code, status)
                        if status == 429:
                            self.assertEqual(failure.exception.headers["Retry-After"], "10")
                        failure.exception.close()
            with self.assertRaises(http.client.RemoteDisconnected):
                urllib.request.urlopen(base + "/metadata/transport", timeout=5)
            for case in ("empty", "missing", "invalid"):
                with urllib.request.urlopen(base + "/metadata/" + case, timeout=5) as response:
                    content = response.read()
                if case == "invalid":
                    with self.assertRaises(json.JSONDecodeError):
                        json.loads(content)
                elif case == "empty":
                    self.assertEqual(json.loads(content)["siblings"], [])
                else:
                    self.assertEqual(json.loads(content)["siblings"][0]["rfilename"], "missing.bin")


class DownloadWiringTests(unittest.TestCase):
    def test_4d_terminal_states_and_safe_streaming_are_wired(self):
        source = (ROOT / "stable-diffusion/Project/Sources/Classes/_Download.4dm").read_text()
        models = (ROOT / "stable-diffusion/Project/Sources/Classes/_models.4dm").read_text()
        start = (ROOT / "stable-diffusion/Project/Sources/Methods/start.4dm").read_text()
        self.assertIn('returnResponseBody:=False', source)
        self.assertIn('automaticRedirections:=False', source)
        self.assertNotIn(".response.body", source)
        self.assertIn('operation: "commit"', source)
        self.assertIn("Function onTerminate(", source)
        self.assertIn("This:C1470.done:=True", source)
        self.assertIn('$request.terminate()', source)
        self.assertIn('operation: "load-plan"', models)
        self.assertIn('operation: "save-plan"', models)
        self.assertIn("This:C1470.advancing", models)
        self.assertNotIn("event.download.new", models)
        self.assertNotIn("$model.start()", start)

    def test_error_reports_preserve_actionable_statuses_without_token_arguments(self):
        models = (ROOT / "stable-diffusion/Project/Sources/Classes/_models.4dm").read_text()
        server = (ROOT / "stable-diffusion/Project/Sources/Classes/_server.4dm").read_text()
        for status in ("401; 403", "$status=404", "$status=429", "$status>=500", "retry-after"):
            self.assertIn(status, models)
        self.assertIn('This:C1470.failed:=True', models)
        self.assertIn('"HF_TOKEN"', server)


if __name__ == "__main__":
    unittest.main()

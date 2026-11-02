import importlib.util
import contextlib
import io
import json
from pathlib import Path
import re
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location("build_server", ROOT / "scripts/build-server.py")
build_server = importlib.util.module_from_spec(spec)
spec.loader.exec_module(build_server)


class BuildConfigurationTests(unittest.TestCase):
    def test_fresh_checkouts_initialize_inference_and_media_submodules(self):
        source = Path("fresh-upstream")
        with mock.patch.object(build_server, "run") as run:
            build_server.initialize_submodules(source)
        run.assert_called_once_with(
            "git", "-C", source, "submodule", "update", "--init", "--recursive",
            "--depth=1", "--", "ggml", "thirdparty/libwebp", "thirdparty/libwebm",
        )

    def test_lock_and_documentation_provenance(self):
        lock = json.loads((ROOT / "scripts/upstream.json").read_text())
        self.assertRegex(lock["revision"], r"^[0-9a-f]{40}$")
        for name in ("README.md", "index.md"):
            text = (ROOT / name).read_text()
            self.assertIn(lock["revision"], text)
            self.assertIn(lock["verified_on"], text)
            self.assertIn(lock["committed_at"][:10], text)
            self.assertIn("b64_json", text)

    def test_macos_slices_keep_metal_and_portable_static_dependencies(self):
        for arch in ("arm64", "x86_64"):
            options = build_server.cmake_options("Darwin", arch, "metal")
            for option in ("-DSD_METAL=ON", "-DGGML_NATIVE=OFF", "-DGGML_OPENMP=OFF",
                           "-DGGML_METAL_EMBED_LIBRARY=ON", "-DSD_BUILD_SHARED_LIBS=OFF",
                           "-DSD_SERVER_BUILD_FRONTEND=OFF", "-DSD_WEBP=ON", "-DSD_WEBM=ON",
                           f"-DCMAKE_OSX_ARCHITECTURES={arch}"):
                self.assertIn(option, options)
            self.assertNotIn("-DSD_BUILD_SERVER=ON", options)

    def test_windows_cpu_and_macos_cpu_override(self):
        for system in ("Windows", "Darwin"):
            options = build_server.cmake_options(system, "x86_64", "cpu")
            self.assertIn("-DSD_METAL=OFF", options)
            self.assertIn("-DGGML_METAL=OFF", options)
            self.assertIn("-DGGML_AVX2=ON", options)
            self.assertIn("-DGGML_NATIVE=OFF", options)

    def test_runtime_keeps_upstream_option_names_and_native_paths(self):
        server = (ROOT / "stable-diffusion/Project/Sources/Classes/_server.4dm").read_text()
        self.assertIn('["clip_l"; "clip_g"; "llm_vision"]', server)
        self.assertNotIn("$option.HONE", server)
        self.assertNotRegex(server, re.escape("expand($arg.value).path"))
        start = (ROOT / "stable-diffusion/Project/Sources/Methods/start.4dm").read_text()
        self.assertIn("$options.options.HOME:=$options.HOME", start)
        model = (ROOT / "stable-diffusion/Project/Sources/Classes/_Model.4dm").read_text()
        self.assertIn("$downloaded.destination; fk platform path", model)
        models = (ROOT / "stable-diffusion/Project/Sources/Classes/_models.4dm").read_text()
        self.assertIn("$event:=cs:C1710.event.event.new()", models)

    def test_server_forwards_existing_diagnostic_callbacks(self):
        server = (ROOT / "stable-diffusion/Project/Sources/Classes/_server.4dm").read_text()
        controller = (ROOT / "stable-diffusion/Project/Sources/Classes/_SD_Controller.4dm").read_text()
        self.assertIn("This:C1470.onData:=$option.onStdOut", server)
        self.assertIn("This:C1470.onDataError:=$option.onStdErr", server)
        for callback in ("onData", "onDataError"):
            self.assertIn(f"Function {callback}(", controller)
            self.assertIn(f"$instance.{callback}.call(", controller)

    def test_windows_pe_reader_against_existing_x64_executable(self):
        path = ROOT / "stable-diffusion/Resources/bin/Windows/sd-server.exe"
        machine, imports = build_server.pe_dependencies(path)
        self.assertEqual(machine, 0x8664)
        self.assertIn("KERNEL32.DLL", imports)
        self.assertIn("MSVCP140.DLL", imports)

    def test_windows_dependency_audit_preserves_crt_but_rejects_sidecars(self):
        for dependencies in (["KERNEL32.DLL", "VCRUNTIME140.DLL", "API-MS-WIN-CRT-RUNTIME-L1-1-0.DLL"],
                             ["LIBSTABLE-DIFFUSION.DLL"], ["VCOMP140.DLL"]):
            with self.subTest(dependencies=dependencies):
                with mock.patch.object(build_server, "pe_dependencies", return_value=(0x8664, dependencies)):
                    if "KERNEL32.DLL" in dependencies:
                        self.assertEqual(build_server.audit_windows(Path("server.exe")), dependencies)
                    else:
                        with self.assertRaises(RuntimeError):
                            build_server.audit_windows(Path("server.exe"))
        with mock.patch.object(build_server, "pe_dependencies", return_value=(0xAA64, [])):
            with self.assertRaises(RuntimeError):
                build_server.audit_windows(Path("server.exe"))

    def test_both_release_paths_require_source_builds(self):
        workflow = (ROOT / ".github/workflows/publish.yml").read_text()
        self.assertIn("uses: ./.github/workflows/build-server.yml", workflow)
        self.assertEqual(workflow.count("needs: server"), 2)
        self.assertEqual(workflow.count("server-artifacts/macOS.tar.gz"), 2)
        self.assertEqual(workflow.count("server-artifacts/Windows.tar.gz"), 2)

    def test_release_versions_clean_checkout_before_replacing_tracked_binaries(self):
        workflow = (ROOT / ".github/workflows/publish.yml").read_text()
        for job in ("publish:", "publish-locally:"):
            body = workflow.split("  " + job, 1)[1]
            body = body.split("\n  publish-locally:", 1)[0]
            with self.subTest(job=job):
                self.assertLess(body.index("- name: set version"),
                                body.index("- name: Stage source-built executables"))
                self.assertLess(body.index("- name: Stage source-built executables"),
                                body.index("- name: build\n"))

    def test_unsupported_configurations_fail_before_fetching_source(self):
        cases = [
            ("Linux", []),
            ("Windows", ["--arch", "arm64"]),
            ("Windows", ["--arch", "universal"]),
            ("Windows", ["--backend", "metal"]),
            ("Darwin", ["--jobs", "0"]),
        ]
        for system, arguments in cases:
            with self.subTest(system=system, arguments=arguments):
                with mock.patch.object(build_server.platform, "system", return_value=system), \
                     mock.patch("sys.argv", ["build-server.py", *arguments]), \
                     mock.patch.object(build_server, "run") as run, \
                     contextlib.redirect_stderr(io.StringIO()):
                    with self.assertRaises(SystemExit) as error:
                        build_server.main()
                    self.assertEqual(error.exception.code, 2)
                    run.assert_not_called()


if __name__ == "__main__":
    unittest.main()

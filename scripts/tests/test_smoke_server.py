import importlib.util
import io
from pathlib import Path
import unittest
from unittest import mock
import urllib.error


ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location("smoke_server", ROOT / "scripts/smoke-server.py")
smoke_server = importlib.util.module_from_spec(spec)
spec.loader.exec_module(smoke_server)


class SmokeStartupTests(unittest.TestCase):
    def setUp(self):
        self.elapsed = 0.0
        self.process = mock.Mock(returncode=None)
        self.process.poll.return_value = None
        self.clock = mock.patch.object(smoke_server.time, "monotonic", side_effect=lambda: self.elapsed)
        self.sleep = mock.patch.object(smoke_server.time, "sleep", side_effect=self.advance)
        self.clock.start()
        self.sleep.start()
        self.addCleanup(self.clock.stop)
        self.addCleanup(self.sleep.stop)

    def advance(self, seconds):
        self.elapsed += seconds

    def test_slow_first_use_backend_can_become_ready_after_old_window(self):
        def request(url, timeout):
            self.assertEqual(url, "http://127.0.0.1:8080/v1/models")
            self.assertGreater(timeout, 0)
            self.assertLessEqual(timeout, 1)
            if self.elapsed < 45:
                raise urllib.error.URLError("connection refused during backend initialization")
            return io.BytesIO(b'{"data":[]}')

        with mock.patch.object(smoke_server.urllib.request, "urlopen", side_effect=request):
            self.assertEqual(
                smoke_server.wait_for_models(self.process, "http://127.0.0.1:8080",
                                             smoke_server.DEFAULT_STARTUP_TIMEOUT),
                {"data": []},
            )
        self.assertGreater(self.elapsed, 30)

    def test_unresponsive_startup_has_a_real_deadline(self):
        def request(url, timeout):
            self.advance(timeout)
            raise TimeoutError("no response")

        with mock.patch.object(smoke_server.urllib.request, "urlopen", side_effect=request):
            with self.assertRaisesRegex(RuntimeError, "within 2 seconds"):
                smoke_server.wait_for_models(self.process, "http://127.0.0.1:8080", 2)
        self.assertEqual(self.elapsed, 2)

    def test_crashed_server_fails_without_waiting_for_deadline(self):
        self.process.poll.return_value = 7
        self.process.returncode = 7
        with mock.patch.object(smoke_server.urllib.request, "urlopen") as request:
            with self.assertRaisesRegex(RuntimeError, "exited with 7"):
                smoke_server.wait_for_models(self.process, "http://127.0.0.1:8080", 300)
        request.assert_not_called()
        self.assertEqual(self.elapsed, 0)

    def test_malformed_success_response_is_not_hidden_by_retry(self):
        with mock.patch.object(smoke_server.urllib.request, "urlopen",
                               return_value=io.BytesIO(b"not JSON")):
            with self.assertRaises(ValueError):
                smoke_server.wait_for_models(self.process, "http://127.0.0.1:8080", 300)
        self.assertEqual(self.elapsed, 0)

    def test_invalid_budget_fails_before_launch(self):
        for timeout in (0, -1, float("nan"), float("inf")):
            with self.subTest(timeout=timeout), mock.patch.object(smoke_server.subprocess, "run") as run:
                with self.assertRaises(ValueError):
                    smoke_server.smoke(Path("not-launched"), timeout)
                run.assert_not_called()


if __name__ == "__main__":
    unittest.main()

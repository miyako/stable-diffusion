#!/usr/bin/env python3
"""Check the real server's CLI and HTTP routes without model weights."""

import argparse
import json
import math
from pathlib import Path
import socket
import subprocess
import tempfile
import time
import urllib.error
import urllib.request


DEFAULT_STARTUP_TIMEOUT = 300.0


def wait_for_models(process, base, startup_timeout):
    deadline = time.monotonic() + startup_timeout
    while True:
        if process.poll() is not None:
            raise RuntimeError(f"Server exited with {process.returncode}")
        remaining = deadline - time.monotonic()
        if remaining <= 0:
            raise RuntimeError(
                f"Server did not become responsive within {startup_timeout:g} seconds; "
                "see startup log for backend initialization errors or delays"
            )
        try:
            with urllib.request.urlopen(base + "/v1/models", timeout=min(1, remaining)) as response:
                return json.load(response)
        except (urllib.error.URLError, TimeoutError):
            remaining = deadline - time.monotonic()
            if remaining > 0:
                time.sleep(min(0.25, remaining))


def smoke(executable, startup_timeout=DEFAULT_STARTUP_TIMEOUT):
    if not math.isfinite(startup_timeout) or startup_timeout <= 0:
        raise ValueError("Startup timeout must be a positive finite number of seconds")
    executable = str(Path(executable).resolve())
    help_text = subprocess.run([executable, "--help"], check=True,
                               capture_output=True, text=True).stdout
    for flag in ("--model", "--diffusion-model", "--clip_l", "--t5xxl",
                 "--llm", "--listen-ip", "--listen-port", "--model-dir"):
        assert flag in help_text, f"Missing server flag: {flag}"
    subprocess.run([executable, "--version"], check=True)
    invalid = subprocess.run([executable, "--invalid-smoke-option"],
                             capture_output=True, text=True)
    assert invalid.returncode != 0, "Unknown CLI options must fail"
    with socket.socket() as sock:
        sock.bind(("127.0.0.1", 0))
        port = sock.getsockname()[1]
    with tempfile.TemporaryDirectory(prefix="sd-smoke-") as directory:
        with tempfile.TemporaryFile(mode="w+") as log:
            process = subprocess.Popen(
                [executable, "--listen-ip", "127.0.0.1", "--listen-port", str(port),
                 "--model-dir", directory], cwd=directory, stdout=log, stderr=log,
            )
            started = time.monotonic()
            try:
                base = f"http://127.0.0.1:{port}"
                # Embedded Metal sources compile on first use, including on Intel CI.
                models = wait_for_models(process, base, startup_timeout)
                print(f"Server responsive after {time.monotonic() - started:.2f}s "
                      f"(startup budget {startup_timeout:g}s)", flush=True)
                assert models == {"data": []}, models
                with urllib.request.urlopen(base + "/", timeout=5) as response:
                    assert response.read().decode() == "Stable Diffusion Server is running"
                with urllib.request.urlopen(base + "/sdcpp/v1/models/status", timeout=5) as response:
                    status = json.load(response)
                assert status["state"] == "empty", status
                request = urllib.request.Request(
                    base + "/v1/images/generations",
                    data=json.dumps({"prompt": "Smoke check", "size": "64x64", "n": 1}).encode(),
                    headers={"Content-Type": "application/json"},
                )
                try:
                    urllib.request.urlopen(request, timeout=5)
                except urllib.error.HTTPError as error:
                    assert error.code == 503, error.code
                    body = json.load(error)
                    assert body["code"] == "model_not_loaded" and body["error"], body
                else:
                    raise AssertionError("Generation without a model must fail")
                print("PASS: CLI help/version, model-less HTTP startup, empty models/status, generation rejection")
            except Exception:
                log.seek(0)
                print(log.read())
                raise
            finally:
                process.terminate()
                try:
                    process.wait(timeout=10)
                except subprocess.TimeoutExpired:
                    process.kill()
                    process.wait()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("executable", type=Path)
    parser.add_argument("--startup-timeout", type=float, default=DEFAULT_STARTUP_TIMEOUT,
                        help="Maximum startup seconds, including first-use Metal compilation (default: 300)")
    args = parser.parse_args()
    if not math.isfinite(args.startup_timeout) or args.startup_timeout <= 0:
        parser.error("--startup-timeout must be a positive finite number")
    smoke(args.executable, args.startup_timeout)

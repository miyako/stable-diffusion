#!/usr/bin/env python3
"""Check the real server's CLI and HTTP routes without model weights."""

import argparse
import json
from pathlib import Path
import socket
import subprocess
import tempfile
import time
import urllib.error
import urllib.request


def smoke(executable):
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
            try:
                base = f"http://127.0.0.1:{port}"
                for _ in range(120):
                    if process.poll() is not None:
                        raise RuntimeError(f"Server exited with {process.returncode}")
                    try:
                        with urllib.request.urlopen(base + "/v1/models", timeout=1) as response:
                            models = json.load(response)
                        break
                    except (urllib.error.URLError, TimeoutError):
                        time.sleep(0.25)
                else:
                    raise RuntimeError("Server did not become responsive")
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
    smoke(parser.parse_args().executable)

#!/usr/bin/env python3
"""Loopback HTTP fixtures for the opt-in real 4D download integration suite."""

import argparse
import hashlib
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import json
import socket

CONTENT = b"fixture model\n"


class FixtureHandler(BaseHTTPRequestHandler):
    def log_message(self, *_):
        pass

    def do_GET(self):
        family, _, case = self.path.lstrip("/").partition("/")
        if family == "metadata" and case == "transport":
            self.connection.shutdown(socket.SHUT_RDWR)
            self.connection.close()
            return
        prefix = "metadata-http-" if family == "metadata" else "http-"
        if case.startswith(prefix):
            status = int(case.removeprefix(prefix))
            self.send_response(status)
            if status == 429:
                self.send_header("Retry-After", "10")
            self.send_header("Content-Length", "0")
            self.end_headers()
            return
        if family == "metadata":
            metadata = {
                "sha": "a" * 40,
                "siblings": [{
                    "rfilename": "model.bin", "blobId": "b" * 40, "size": len(CONTENT),
                    "lfs": {"size": len(CONTENT), "sha256": hashlib.sha256(CONTENT).hexdigest()},
                }],
            }
            if case == "empty":
                metadata["siblings"] = []
            if case == "missing":
                metadata["siblings"][0]["rfilename"] = "missing.bin"
            body = b"<html>not JSON</html>" if case == "invalid" else json.dumps(metadata).encode()
            self.send_response(200)
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)
            return
        if family == "download":
            body = b"x" * len(CONTENT) if case == "corrupt" else CONTENT
            if case == "truncated":
                body = CONTENT[:-3]
            self.send_response(200)
            self.send_header("Content-Type", "application/octet-stream")
            if case != "no-length":
                length = len(CONTENT) + 1 if case == "wrong-length" else len(CONTENT)
                self.send_header("Content-Length", str(length))
            self.send_header("Connection", "close")
            self.end_headers()
            self.wfile.write(body)
            self.close_connection = True
            return
        self.send_error(404)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--port", type=int, default=40480)
    args = parser.parse_args()
    server = ThreadingHTTPServer(("127.0.0.1", args.port), FixtureHandler)
    print(f"4D download fixture: http://127.0.0.1:{server.server_port}", flush=True)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        server.server_close()

# stable-diffusion

Use [stable-diffusion.cpp](https://github.com/leejet/stable-diffusion.cpp) locally
from **4D 20+**, or run its HTTP server directly. See the
[4D integration guide](https://miyako.github.io/stable-diffusion/) for callbacks,
model downloads and AI Kit usage.

## Source and supported packages

The source lock is [`scripts/upstream.json`](scripts/upstream.json):
**[`290148d2e31ca6ef9757d567905776b5f3646db5`](https://github.com/leejet/stable-diffusion.cpp/commit/290148d2e31ca6ef9757d567905776b5f3646db5)**,
committed **2026-11-01 17:19:28 UTC**, verified **2026-11-02**.
This is the latest upstream `master` revision checked on that date, not a moving
`latest` download.

| Package | Architecture | Backend / prerequisites |
| --- | --- | --- |
| macOS | Universal: Apple Silicon + Intel | Metal + CPU/Accelerate; macOS 14+; Intel CPU requires AVX2 |
| Windows | x64 | CPU, AVX2; Windows 10/11 and Visual C++ 2015-2022 x64 runtime |

Both `sd-server` and `sd-cli` are built from the same source revision. Libraries
are statically linked apart from OS frameworks and the Windows compiler runtime;
Metal kernels are embedded. WebP/WebM support is retained. The optional upstream
web frontend is **not built**: `/` returns a status message; use the HTTP APIs.
CUDA, Vulkan, ROCm, Linux and Windows ARM are not added as supported packages.
Model families, memory needs and backend support vary; consult the
[pinned upstream documentation](https://github.com/leejet/stable-diffusion.cpp/tree/290148d2e31ca6ef9757d567905776b5f3646db5/docs).

Packages also include this repository's small native **`sd-cache`** helper for
4D download integrity/atomic cache replacement; standalone server use does not
require it. It uses system crypto APIs, not a deployed Python runtime.

## Install

For 4D, install the component from an approved
[release](https://github.com/miyako/stable-diffusion/releases) into your database's
`Components` folder. Its `tcp`, `workers` and `event` dependencies are declared
in `stable-diffusion/Project/Sources/dependencies.json`.

The **Build upstream server** Actions workflow produces `server-macOS` and
`server-Windows` artifacts without publishing a release. Extract the contained
`.tar.gz` into `stable-diffusion/Resources/bin/` (or any directory for standalone
use). Keep `build-info.json` and `licenses/` with the executables. The existing
checked-in binaries are **legacy snapshots**, not evidence of this source lock;
source builds stage into `.build/package/` and release packaging replaces both
platforms with fresh artifacts before building the 4D component.

On macOS the script ad-hoc signs executables; this is not Developer ID
notarization. The existing release workflow handles signing/notarization with
repository secrets. Respect macOS download/quarantine policy.

## Verified 4D model downloads

The current 4D sources require the matching native package **including
`sd-cache`** in `Resources/bin/{macOS,Windows}`. Old checked-in resource snapshots
do not include it and report a missing-helper error; build/stage fresh resources
before running the updated source component.

Downloads query Hugging Face repository metadata with `?blobs=true` and pin
each file URL to the returned repository commit. LFS bytes are verified against
`lfs.sha256`; ordinary Git files use the Git blob SHA-1 (including its
`blob <size>\0` header). LFS pointer IDs, Xet hashes and arbitrary ETags are not
treated as model SHA-256 digests. Existing files are hashed, not trusted by size.
Hashing multi-GB caches takes time and does not emit HTTP progress callbacks.

GET bodies stream once into unique adjacent `.sd-part-*` files. Only a
size/hash-verified candidate atomically replaces the final file. Failed or
interrupted downloads never become cache hits or replace existing good data.
Missing/invalid metadata, requested files or empty requests fail explicitly.
Folder descriptors may download all files or an exact subset; specify a primary
weight with `name`/the first selected path, or provide a repository containing
exactly one recognized weight file. README/config files do not become model
arguments. Individual `4D.File` destinations are recommended.

`event.onError` receives an actionable `message`: 401/403 explain access/token
or gated-model license acceptance; 404 identifies repository/filename problems;
429 includes Retry-After when supplied; 5xx and transport failures are reported.
The batch stops once rather than hanging or starting the server after a failure.
Callbacks retain `onData(request; event)` and `onResponse(request; event)`;
`This.file` is the final cache path. `onResponse` runs only after a downloaded
file is verified/promoted; verified cache hits do not emit HTTP callbacks.
Callback errors also fail the batch. Server `onSuccess` still means process
launch, **not model readiness**.

For private/gated models, pass `HF_TOKEN` in the constructor's options object
(for example, `$options.HF_TOKEN:=$token`). Obtain it through your application's
secret handling, not checked-in code. It is not forwarded as a server argument
or sent to CDN redirect hosts. Production redirects require HTTPS.

**Offline:** after a successful online verification, an atomic
`.sd-download-<identity>.json` receipt records authoritative metadata beside
the cache. Metadata transport failure may use that receipt only if every file
still hashes correctly. HTTP errors/invalid metadata do not silently fall back.
Missing, corrupt or unreceipted offline caches fail clearly. Legacy caches need
one online verification; matching files are reused without downloading again.
Keep receipts with the cache, do not edit them, and trust only your own local
cache directory; receipts are integrity records, not signed attestations.
There is no automatic retry/resume or cross-process transfer scheduler. Interrupted
temporary candidates may need cleanup after confirming no download is active.

## Build from source

Prerequisites: Git, Python 3.9+, CMake 3.24+, a C/C++17 compiler and internet
access for source/submodules. On macOS install Xcode Command Line Tools and
Ninja (`xcode-select --install`, then `brew install cmake ninja` if needed).
On Windows install Visual Studio 2022 with **Desktop development with C++**,
a Windows SDK, CMake and Python. No Node/pnpm, model weights or GPU SDK download
is needed for these packages.

```sh
# macOS: build both slices, combine with lipo, stage and smoke check
python3 scripts/build-server.py --arch universal

# Faster local Apple Silicon-only build (not a universal release package)
python3 scripts/build-server.py --arch arm64

# Intel-only build
python3 scripts/build-server.py --arch x86_64

# CPU-only diagnostic build
python3 scripts/build-server.py --backend cpu
```

```powershell
# Windows x64, Visual Studio 2022 generator, Release configuration
python scripts/build-server.py --arch x86_64
```

Outputs are `.build/package/macOS/` or `.build/package/Windows/`. The script
builds the real CMake targets **`sd-server` and `sd-cli`**, explicitly enables
`SD_BUILD_EXAMPLES`, disables `SD_SERVER_BUILD_FRONTEND`, and uses `SD_METAL=ON`
on macOS. There is no active `SD_BUILD_SERVER` option at this revision.
It disables host-native tuning and OpenMP (no external `libomp` dependency),
initializes the pinned WebP/WebM submodules, and records the resolved source,
submodule revisions, CMake options and executable SHA-256 hashes in
`build-info.json`. It separately builds/packages `native/cache` for each target,
recording the helper source hash. Universal cross-compilation is followed by a native smoke
check; CI additionally runs the package on an Intel Mac.
The source/submodule revisions are pinned; compiler/SDK updates can still
change the resulting binary bytes. The release workflow's `use_self_hosted`
option selects the Mac for 4D packaging only; fresh server builds still need
the GitHub-hosted macOS and Windows jobs.
Architecture and runtime-dependency audits reject wrong slices, external macOS
libraries, or unbundled Windows DLLs other than system/VC++ runtime libraries.
`build-info.json` hashes describe the source-build artifacts after local signing;
downstream Developer ID signing can change bytes, so these are not checksums
of the final signed release distribution.

`--jobs 4`, `--work-dir PATH` and `--output PATH` control build resources and
staging. To stage directly into 4D resources, use a matching-platform build:

```sh
python3 scripts/build-server.py --arch universal --output stable-diffusion/Resources/bin/macOS
```

Evaluate an upstream update with
`python3 scripts/build-server.py --ref <full-commit-sha> --arch universal`
(or the workflow's `upstream_ref` input). It records the resolved SHA even when
given a tag. After reviewing upstream changes and checking both platforms,
update the lock's revision/date and the provenance in both this file and
`index.md`. Releases always use the reviewed lock, never the dispatch override.
Reusing a source directory with local changes is rejected; use a different
`--work-dir` instead.

## Run and call the API

Use a compatible **local checkpoint file**, not a model directory:

```sh
.build/package/macOS/sd-server \
  --model "/absolute/path/to/model.gguf" \
  --listen-ip 127.0.0.1 --listen-port 8080
```

```powershell
& .\.build\package\Windows\sd-server.exe `
  --model "C:\Models\model.gguf" `
  --listen-ip 127.0.0.1 --listen-port 8080
```

Split models require matching components, e.g. `--diffusion-model FILE`,
`--vae FILE`, `--clip_l FILE`, `--t5xxl FILE` or `--llm FILE`, depending on the
model. Run `sd-server --help` and follow the model-specific upstream guide.
The standalone server defaults to port **1234**; the 4D wrapper defaults to
**8080**.

```sh
curl --fail-with-body http://127.0.0.1:8080/v1/models
curl --fail-with-body http://127.0.0.1:8080/v1/images/generations \
  -H "Content-Type: application/json" \
  -d '{"prompt":"A futuristic city, cinematic lighting","size":"512x512","n":1,"output_format":"png"}' \
  -o response.json

# Decode the first PNG, not raw RGB data or a URL
python3 -c 'import json,base64; from pathlib import Path; r=json.loads(Path("response.json").read_text()); Path("image.png").write_bytes(base64.b64decode(r["data"][0]["b64_json"]))'
```

Responses contain **`data[].b64_json`**, not image URLs.
`response_format: "url"` is not implemented by this upstream server. Set AI
clients' base URL to `http://127.0.0.1:8080/v1` and request/consume base64 images.
Images/edits and models are supported, not chat or embeddings; this is partial
OpenAI compatibility. See the
[pinned API reference](https://github.com/leejet/stable-diffusion.cpp/blob/290148d2e31ca6ef9757d567905776b5f3646db5/examples/server/api.md).

For a model-free startup check:

```sh
python3 scripts/smoke-server.py .build/package/macOS/sd-server
python3 -m unittest discover -s scripts/tests -v
```

The download suite executes the packaged helper against Git/LFS metadata,
corrupt/truncated caches, real loopback HTTP bytes and offline receipts.
It also checks fixture HTTP/transport failures and 4D source wiring; these are
**not proof of 4D callback execution**. The opt-in real 4D integration harness
and setup are in [`tests/4d/README.md`](tests/4d/README.md).
The reusable cross-repository implementation/testing guide is
[`.github/skills/4d-http-download/SKILL.md`](.github/skills/4d-http-download/SKILL.md).

The smoke check starts on loopback with an empty temporary model directory,
checks `/v1/models` and `/sdcpp/v1/models/status`, and confirms generation
returns HTTP 503 without a loaded model. This does **not** validate image
generation quality, model compatibility or GPU inference. No weights are
downloaded by the build/check scripts. The 4D default constructor, in contrast,
downloads its configured SDXL Turbo checkpoint when needed.

Keep the server on loopback: it has no authentication/TLS boundary.
Binding `0.0.0.0` exposes model-management and generation APIs; use a secured
reverse proxy and firewall if remote access is required. Model weights have
their own licenses and may require several GB of RAM/disk.

`ai_studio_code.cpp`, `cpp/` and `include/` are legacy prototype/library
snapshots; they are not inputs to the server build. The server comes from the
pinned upstream checkout, without local inference/API patches.

The workflow follows the native-build conventions in
[llama-cpp](https://github.com/miyako/llama-cpp),
[CTranslate2](https://github.com/miyako/CTranslate2) and
[onnx-genai](https://github.com/miyako/onnx-genai): separate source/component
versions, portable architecture builds, dependency audits, model-free packaged
smoke checks, read-only native jobs and the existing 4D semantic-version/signing
release actions. Here native artifacts are handed directly to both publication
paths in the same run, without committing generated binaries or relying on a
bot push. Tar preserves executable modes. Unlike the static-CRT examples,
Windows retains the existing VC++ runtime prerequisite because upstream WebM
selects the DLL CRT. No extra Windows ARM package or independent standalone
Developer ID/notarization pipeline is introduced.

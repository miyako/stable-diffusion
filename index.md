---
layout: default
---

![version](https://img.shields.io/badge/version-20%2B-E23089)
![platform](https://img.shields.io/static/v1?label=platform&message=mac-intel%20|%20mac-arm%20|%20win-64&color=blue)
[![license](https://img.shields.io/github/license/miyako/stable-diffusion)](https://github.com/miyako/stable-diffusion/blob/main/LICENSE)
![downloads](https://img.shields.io/github/downloads/miyako/stable-diffusion/total)

# Use Stable Diffusion from 4D

#### Abstract

[**stable-diffusion.cpp**](https://github.com/leejet/stable-diffusion.cpp) is a
C/C++ diffusion inference engine supporting SD, FLUX and other image/video model
families. This component runs its local HTTP server from **4D 20+**.

#### Install and provenance

Install the component from an approved
[release](https://github.com/miyako/stable-diffusion/releases) in your database's
`Components` folder. The project declares the `tcp`, `workers` and `event`
dependencies. Model weights are separate and have their own licenses.

The verified upstream source is
[`290148d2e31ca6ef9757d567905776b5f3646db5`](https://github.com/leejet/stable-diffusion.cpp/commit/290148d2e31ca6ef9757d567905776b5f3646db5)
(committed **2026-11-01 17:19:28 UTC**, checked **2026-11-02**), the latest
`master` checked on that date. Builds use the reviewed
[`scripts/upstream.json`](https://github.com/miyako/stable-diffusion/blob/main/scripts/upstream.json)
lock, not an unpinned latest download.

| Package | Architecture | Backend / prerequisites |
| --- | --- | --- |
| macOS | Universal Apple Silicon + Intel | Metal + CPU/Accelerate; macOS 14+; AVX2 on Intel |
| Windows | x64 | CPU, AVX2; Windows 10/11; Visual C++ 2015-2022 x64 runtime |

Both `sd-server` and `sd-cli` are built from source, with WebP/WebM support,
embedded Metal kernels and no external OpenMP library. The optional upstream
web frontend is disabled; the HTTP APIs remain available. CUDA/Vulkan/ROCm,
Linux and Windows ARM are not packaged here.

The **Build upstream server** workflow produces resource archives without
publishing releases. Extract its `macOS.tar.gz` / `Windows.tar.gz` under
`stable-diffusion/Resources/bin/`; keep `build-info.json` and `licenses/`.
The checked-in binaries are legacy snapshots, not the locked build. The
component release workflow replaces both platforms with freshly built artifacts
before packaging. Local macOS builds are ad-hoc signed, not notarized.
Packages additionally include the local native `sd-cache` integrity helper,
required by the updated 4D downloader but not by standalone server users.
Keep it alongside the server/CLI; no deployed Python runtime is needed.

#### Build from source

Use Git, Python 3.9+, CMake 3.24+ and a C/C++17 compiler. macOS additionally
needs Xcode Command Line Tools and Ninja; Windows needs Visual Studio 2022's
Desktop development with C++ workload and a Windows SDK.

```sh
# macOS: both architectures, Metal + CPU
python3 scripts/build-server.py --arch universal
# Faster local builds: --arch arm64 or --arch x86_64
# CPU diagnostics: --backend cpu
```

```powershell
# Windows x64 / CPU
python scripts/build-server.py --arch x86_64
```

Outputs: `.build/package/macOS/` and `.build/package/Windows/`. The actual CMake
targets are `sd-server` and `sd-cli`, enabled by `SD_BUILD_EXAMPLES=ON`;
`SD_BUILD_SERVER` is not an active option. macOS uses `SD_METAL=ON`, and
`SD_SERVER_BUILD_FRONTEND=OFF` avoids a Node/pnpm dependency.

Use `--ref <full-commit-sha>` to evaluate an update, then review and update the
lock and both documentation pages after checking both platforms. Releases
always use the lock. See the
[repository README](https://github.com/miyako/stable-diffusion#build-from-source)
for staging, overrides, checks and build provenance.
The lock pins source/submodules, not byte-identical output across compiler/SDK
updates. `use_self_hosted` selects the Mac for 4D packaging only; server builds
still run on GitHub-hosted macOS and Windows.
Architecture/dependency audits follow the native-build conventions used in
[llama-cpp](https://github.com/miyako/llama-cpp),
[CTranslate2](https://github.com/miyako/CTranslate2) and
[onnx-genai](https://github.com/miyako/onnx-genai).
Windows intentionally retains the VC++ runtime prerequisite (upstream WebM
uses the DLL CRT). Manifest hashes cover locally signed source-build artifacts,
not the final release container after Developer ID signing/notarization.

#### Usage from 4D

Instantiate `cs.SD.SD` in your **On Startup** database method. The constructor
is `new(port; huggingfaces; HOME; options; event)`:

```4d
var $SD : cs.SD.SD
var $homeFolder : 4D.Folder
$homeFolder:=Folder(fk home folder).folder(".Stable-Diffusion")
$homeFolder.create()

var $model : 4D.File
$model:=$homeFolder.file("gpustack/stable-diffusion-xl-1.0-turbo/stable-diffusion-xl-1.0-turbo-Q4_0.gguf")

var $image : cs.event.huggingface
$image:=cs.event.huggingface.new($model; \
    "gpustack/stable-diffusion-xl-1.0-turbo-GGUF/stable-diffusion-xl-1.0-turbo-Q4_0.gguf"; \
    ""; "image"; "stable-diffusion-xl-1.0-turbo-Q4_0.gguf")

var $huggingfaces : cs.event.huggingfaces
$huggingfaces:=cs.event.huggingfaces.new([$image])

var $event : cs.event.event
$event:=cs.event.event.new()
$event.onError:=Formula(ALERT($2.message))
$event.onSuccess:=Formula(LOG EVENT(Into 4D debug message; "Server process started; poll model status before generating"))
$event.onData:=Formula(LOG EVENT(Into 4D debug message; This.file.fullName+": downloading"))
$event.onResponse:=Formula(LOG EVENT(Into 4D debug message; This.file.fullName+": download complete"))
$event.onStdOut:=Formula(LOG EVENT(Into 4D debug message; $2.data))
$event.onStdErr:=Formula(LOG EVENT(Into 4D debug message; $2.data))
$event.onTerminate:=Formula(LOG EVENT(Into 4D debug message; "Server process terminated"))

var $options : Object
$options:={listen_ip: "127.0.0.1"; cfg_scale: 1; steps: 4; sampling_method: "euler"}
$SD:=cs.SD.SD.new(8080; $huggingfaces; $homeFolder; $options; $event)
```

`cs.SD.SD.new()` uses port 8080 and the default SDXL Turbo checkpoint download.
If the component's worker is already running on that port, it does not start
another one. An unrelated process occupying the port reports an error.
Downloads and process launch run in the background. **`onSuccess` means the
process has been started, not that weights have finished loading**; retry
`GET /sdcpp/v1/models/status` until its `state` is `ready` before generating.
Use `onError`/`onTerminate` for failures.
`onStdOut` and `onStdErr` receive the server's diagnostic output.

Use individual `4D.File` objects for checkpoints, VAE and text encoders. Model
domains map `image` to `--model`, `diffusion` to `--diffusion-model`, and
`vae`, `clip_l`, `t5xxl`, `llm` to their corresponding arguments.
The wrapper preserves upstream underscore flags such as `--clip_l`;
other option keys such as `listen_ip` and `cfg_scale` become hyphenated flags.
Use native `platformPath` file paths, especially on Windows.

#### Verified downloads and offline use

Use the fresh native resource package, **including `sd-cache`**, with the
updated 4D sources. Legacy checked-in binaries lack this helper and report
an explicit missing-helper error.

The component fetches authoritative Hugging Face `?blobs=true` metadata and
downloads against its immutable repository commit. It verifies LFS SHA-256
or ordinary Git blob SHA-1, not just file size; a Git LFS pointer ID, Xet hash
or arbitrary ETag is not a downloaded model SHA-256.
Existing files are hashed too, which takes time for large models.

Files stream into adjacent `.sd-part-*` candidates; only verified bytes
atomically replace final cache files. Failed/partial downloads never count
as valid cache or replace good existing content. Missing/invalid metadata,
missing files and empty requests stop with an error. For folder descriptors,
select a primary model through `name`/the first selected path, or use a
repository with exactly one recognized weight file. README/config downloads
must not select the server's model argument. Individual `4D.File` destinations
remain the recommended integration.

`event.onError` receives actionable HTTP 401/403/404/429/5xx, transport,
integrity and callback failures; the batch fails once instead of hanging.
401/403 require checking model access/license acceptance and credentials;
429 reports Retry-After when available. Put a token in `$options.HF_TOKEN`
using your application's secret handling; never commit it. The token is not
a server CLI option and is stripped on HTTPS CDN redirects.
`onData(request; event)` and `onResponse(request; event)` retain their shared
signatures and `This.file` final path. `onResponse` follows verified promotion;
cache hits emit no HTTP progress/response callback. There is no automatic
retry/resume or cross-process transfer scheduler.

After complete online verification, `.sd-download-<identity>.json` receipts
are written beside the cache. A metadata **transport** failure can use these
only after rehashing every cached file. HTTP errors or invalid metadata do
not trigger offline fallback. Missing/corrupt/unreceipted offline caches fail
clearly; old caches need one online verification, not necessarily redownloading.
Keep receipts with trusted local caches; they are not signed attestations.
Interrupted candidates can be removed only after confirming no download is active.
The server process-start callback remains distinct from model readiness.

#### Standalone server and HTTP API

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

The standalone default port is 1234; the 4D wrapper uses 8080.
Split model families also need compatible VAE/text encoders: consult
`sd-server --help` and the
[pinned model guides](https://github.com/leejet/stable-diffusion.cpp/tree/290148d2e31ca6ef9757d567905776b5f3646db5/docs).

```sh
curl --fail-with-body http://127.0.0.1:8080/sdcpp/v1/models/status
curl --fail-with-body http://127.0.0.1:8080/v1/images/generations \
  -H "Content-Type: application/json" \
  -d '{"prompt":"A futuristic city, cinematic lighting","size":"512x512","n":1,"output_format":"png"}' \
  -o response.json
python3 -c 'import json,base64; from pathlib import Path; r=json.loads(Path("response.json").read_text()); Path("image.png").write_bytes(base64.b64decode(r["data"][0]["b64_json"]))'
```

The response carries **base64-encoded PNG bytes in `data[].b64_json`**, not a
download URL. `response_format: "url"` is not implemented. `output_format`
can be `png`, `jpeg` or `webp`.

#### AI Kit compatibility

Use [4D AI Kit](https://developer.4d.com/docs/aikit/overview)'s OpenAI client
with base URL **`http://127.0.0.1:8080/v1`**, not the complete generations
endpoint. Set `response_format` to `b64_json`; the server always returns base64
images. For the AI Kit version exposing the classes below:

```4d
var $AIClient : cs.AIKit.OpenAI
$AIClient:=cs.AIKit.OpenAI.new()
$AIClient.baseURL:="http://127.0.0.1:8080/v1"
$AIClient.apiKey:=""

var $parameters : cs.AIKit.OpenAIImageParameters
$parameters:=cs.AIKit.OpenAIImageParameters.new()
$parameters.size:="512x512"
$parameters.response_format:="b64_json"

var $result : cs.AIKit.OpenAIImagesResult
$result:=$AIClient.images.generate("A futuristic city, cinematic lighting"; $parameters)
If ($result.image#Null)
    $result.image.saveToDisk(Folder(fk desktop folder).file("skylinecity.png"))
End if
```

Check the result's errors through your AI Kit version's error handling before
using an image. This is **partial** OpenAI image API compatibility, not a
general OpenAI server. See the
[pinned API reference](https://github.com/leejet/stable-diffusion.cpp/blob/290148d2e31ca6ef9757d567905776b5f3646db5/examples/server/api.md).

| API | Availability |
| --- | --- |
| `GET /v1/models` | Available; empty until a model is loaded |
| `POST /v1/images/generations` | Available; base64 response |
| `POST /v1/images/edits` | Available; multipart upload, model-dependent |
| `/v1/chat/completions`, `/v1/embeddings`, `/v1/moderations`, `/v1/files` | Not provided |

Finally, terminate the component's server:

```4d
var $SD : cs.SD.SD
$SD:=cs.SD.SD.new()
$SD.terminate()
```

#### Models, checks and caveats

Model files may require multiple GB of disk/RAM; use matching encoders and VAE
for your model family. The 4D default downloads SDXL Turbo if absent. Builds
and model-free checks do **not** download weights or prove inference quality.

```sh
python3 scripts/smoke-server.py .build/package/macOS/sd-server
python3 -m unittest discover -s scripts/tests -v
```

The smoke check verifies help/version, a temporary model-less server, empty
models/status and HTTP 503 when generating without weights. Windows and both
macOS architectures are covered by the source-build workflow.
Download tests execute `sd-cache`, real loopback HTTP fixtures and integrity/
offline cases, plus static 4D wiring checks. They do **not** establish real 4D
callback execution; use the opt-in
[4D integration harness](https://github.com/miyako/stable-diffusion/tree/main/tests/4d).
See the reusable
[4D HTTP download skill](https://github.com/miyako/stable-diffusion/blob/main/.github/skills/4d-http-download/SKILL.md)
for lifecycle, hash semantics, error contracts and cross-repository pitfalls.

Keep the server bound to `127.0.0.1`. It does not provide authentication or TLS.
`0.0.0.0` exposes generation and model-management APIs to the network; use a
secured reverse proxy and firewall if remote access is necessary.

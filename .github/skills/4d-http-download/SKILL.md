---
name: 4d-http-download
description: Harden or port 4D HTTPRequest and Hugging Face model downloads, including callback completion, authoritative Git/LFS integrity, atomic caches, offline receipts, authentication and regression testing.
---

# Reliable 4D HTTP/model downloads

Use this skill when a 4D component downloads large assets, particularly when
porting the shared `miyako/event` Hugging Face descriptor/download pattern.
Trace the destination, metadata, network callbacks, queue and worker cleanup
before editing. Do not equate HTTP completion, matching size or an ETag with
verified content.

## Evidence and implementation map

The local implementation is:

- `stable-diffusion/Project/Sources/Classes/_models.4dm`: descriptor validation,
  metadata/status handling, offline policy, sequential queue and completion.
- `_Download.4dm` in that directory: actual 4D HTTP streaming/redirect callbacks.
- `_DownloadCache.4dm`, `Methods/sdDownloadIO.4dm`, `Methods/sdDownloadError.4dm`:
  helper invocation and scoped 4D error capture.
- `_Model.4dm`, `Methods/onModel.4dm`, `Methods/start.4dm`: verified model binding,
  actionable error propagation and worker cleanup; no offline launch bypass.
- `native/cache/main.cpp`: bounded-memory digests, metadata plans, receipts and
  same-directory atomic promotion. `scripts/build-server.py` packages `sd-cache`.
- `scripts/tests/test_download_cache.py`, `scripts/tests/download_fixture.py`,
  `tests/4d/`: native tests, HTTP fixtures and opt-in real 4D callback harness.

Research baseline: `miyako/event` commit
`5b4faa616b96c6de1fb8d598aaad11d1c6f6a06a`, classes
`download`, `huggingface`, `huggingfaces`, `event`, `error`. Its shared downloader
streams to final cache files, uses size checks, and lacks terminal handling for
some HTTP responses. Related `_models.4dm` patterns also exist in
`miyako/llama-cpp`, `miyako/CTranslate2`, `miyako/onnx-genai`; they are portability
targets, not proof this fix has been applied there. This component retains shared
descriptors/events but deliberately replaces the unsafe transfer implementation.
Do not modify shared dependencies or sibling repositories incidentally.

## Upstream identities: do not guess

Fetch `https://huggingface.co/api/models/OWNER/REPO/revision/main?blobs=true`.
Validate the object, immutable repository `sha`, nonempty `siblings`, every
selected `rfilename`, integer size and authoritative digest. Resolve downloads
against that repository commit, not mutable `main`.

| Metadata | Meaning / verification |
| --- | --- |
| `siblings[].lfs.sha256` | SHA-256 of downloaded LFS content; require matching `lfs.size` |
| Ordinary `siblings[].blobId` | Git SHA-1: hash `blob <decimal-byte-size>\0` followed by file bytes |
| LFS `blobId` | Git identity of the pointer, **not** of downloaded model bytes |
| Tree API `oid`, `lfs.oid` | Different schema; inspect it rather than reusing repo-info keys |
| `xetHash`, ETag | Not assumed to be a plain content SHA-256 |

Reference: [HF model-info API](https://huggingface.co/docs/hub/api#get-apimodelsrepo_id),
[Git object storage](https://git-scm.com/book/en/v2/Git-Internals-Git-Objects),
[Git LFS pointer format](https://github.com/git-lfs/git-lfs/blob/main/docs/spec.md).
Recheck schemas when changing endpoints. Tree endpoints may require pagination.

## Lifecycle and failure contract

4D's documented sequence is `onHeaders`, zero/more `onData`, `onResponse` **or**
`onError`, then `onTerminate`. HTTP 401/403/404/429/5xx are responses, not
necessarily transport errors. `.response` is undefined until a status arrives.
Check both status and `.errors`. Read lowercase response headers on 4D 20.

Implemented rules:

1. Validate descriptors before forming authenticated URLs. Reject missing files,
   unsafe/traversing paths, nested symlinks, conflicting destinations and empty
   requests. Never let an empty queue imply successful model acquisition.
2. Use one GET with `returnResponseBody=False`, an `onData` handler and identity
   encoding. Write each chunk once, never append `.response.body` as well.
   HEAD/range/resume support is not required.
3. Use a unique adjacent candidate. Accept 200 only; verify supplied
   Content-Length, bound streamed size, then hash the closed candidate.
   Never delete or overwrite a good final cache to start a transfer.
4. Promote only verified bytes with native same-filesystem replacement:
   POSIX rename after sync, or Windows MoveFileEx replacement/write-through.
   4D File.rename/moveTo refuses replacement; delete-then-rename is not atomic.
   Large files are hashed in 1 MiB chunks; do not load GB models into a Blob.
5. Use per-queue IDs, not content OIDs (identical files may share OIDs).
   Guard `done`, `failed`, `completed` and cached-queue reentrancy. `.wait()`
   executes other callbacks. After redirects, old request termination must not
   fail the replacement request.
6. Every unsuccessful status, transport error, unexpected termination, IO/helper
   error or progress/response callback error terminates the batch explicitly.
   Success notifications follow integrity/promotion. One batch starts once or
   fails once; do not continue past a failed item.
7. Preserve caller error handlers using scoped ON ERR CALL and captured
   `Last errors`. Restore state even around nested waits. Error callbacks must
   not prevent worker cleanup. Keep model-load readiness a separate concern.

Authentication is `options.HF_TOKEN`, never a server CLI argument or logged
secret. Automatic redirects are disabled; only exact `https://huggingface.co/`
receives Authorization. Validated HTTPS CDN redirects drop it and are bounded
to five hops. HTTP error messages include access/license advice for 401/403,
filename/repository advice for 404, Retry-After for 429 and retry advice for 5xx.
There is no automatic retry storm or insecure TLS fallback.

Reference: [HTTPRequest](https://developer.4d.com/docs/API/HTTPRequestClass),
[SystemWorker](https://developer.4d.com/docs/API/SystemWorkerClass),
[FileHandle](https://developer.4d.com/docs/API/FileHandleClass).

## Offline/cache policy and boundaries

An online run verifies even preexisting cache files against upstream metadata.
Only after the entire descriptor succeeds is a metadata receipt atomically
written beside the model/root. Metadata transport failure may use that receipt
only after rehashing **all** its files. HTTP failures and invalid metadata do
not trigger offline fallback. Missing/corrupt/unreceipted offline caches fail
with an actionable message; legacy caches need one online verification, not
necessarily another download.

Receipts are local integrity records, **not signed attestations**: this assumes
a trusted local cache/receipt directory. Files can still be changed by external
software after verification. Interrupted `.sd-part-*` files are never cache hits;
cleanup must not delete another active transfer's candidates. A stale receipt
`.tmp` fails explicitly rather than racing another writer. No cross-process
download scheduler, resumption, or automatic receipt-lock recovery is implemented.

Folder descriptors retain full/exact-subset download behavior but must identify
one primary weight via name/first selected path, or contain exactly one recognized
weight file. Only that file binds the server option, not the last README/config
downloaded. Check each consumer's model-directory semantics before porting this.

## Testing and portability recipe

Build/stage the real helper, then:

```sh
SD_CACHE_EXECUTABLE="$PWD/.build/package/macOS/sd-cache" \
  python3 -m unittest discover -s scripts/tests -v
python3 scripts/tests/download_fixture.py --port 40480
```

For Windows select `.build/package/Windows/sd-cache.exe`. Follow
`tests/4d/README.md` in a disposable 4D project copy to execute the real callbacks.
Cover cached/online/offline success, absent receipts/files, malformed/empty
metadata, 401/403/404/429/5xx, dropped connections, truncated/oversized/same-size
corruption, failed promotion preserving old data and exactly-once completion.

Native/fixture/static tests **do not prove 4D execution**. State explicitly if
4D/Windows runtime validation is unavailable. Package/test both helper
architectures, executable modes, relocation and native dependency closure.
Do not introduce a Python runtime requirement into deployed 4D components.
Future retries/resume, cross-process locks or shared-library extraction require
their own tests and policy; they are recommendations, not current guarantees.

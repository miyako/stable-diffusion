---
name: 4d-native-release
description: Diagnose and verify reproducible native server builds and 4D component releases, including submodules, Metal startup, clean-checkout versioning, compiler severity, signed artifacts and publication evidence.
---

# Native builds and 4D release verification

Use for source-build or Publish failures in this repository and comparable
4D components. Read current remote state, actual job logs and the relevant
shared action implementation before changing behavior. Preserve user changes;
never assume a previous failure is the current failure.

## Repository map

- `scripts/upstream.json`: verified source revision and date.
- `scripts/build-server.py`: source initialization, native build and packaging.
- `scripts/smoke-server.py`: model-free HTTP startup check and timeout budget.
- `.github/workflows/build-server.yml`: native platforms and Intel smoke job.
- `.github/workflows/publish.yml`: hosted/self-hosted 4D publication paths.
- `scripts/tests/`: focused configuration, startup and native helper tests.

Do not silently expand platform/backend scope. Inspect actual upstream CMake
targets and options; old flags and executable names are not authoritative.
Keep deployment resource paths, dependency closure and documentation consistent.

## Clean-room source initialization

A successful build from a reused source directory does not prove a fresh CI
checkout can build. The missing `ggml` submodule failure was masked locally by
an already populated checkout. Initialize the required submodules recursively
at the superproject's pinned gitlinks, then reproduce from an empty destination.
This project needs `ggml`, `thirdparty/libwebp` and `thirdparty/libwebm`.

Fetch the pinned source revision, not a mutable branch head, and retain an
explicit override/update path. Do not fetch unrelated large submodules merely
to hide an incomplete dependency inventory.

## Metal first-start budgets

Embedded Metal kernels can compile during first startup. A hosted Intel run
of this package became HTTP-responsive after 90.48 seconds; a 30-second gate
was insufficient. This is one observation, not a universal startup guarantee.

Use a bounded, configurable monotonic deadline, log elapsed time, detect early
process exit, check actual HTTP readiness and always clean up the child process.
The current default is 300 seconds. Test real Intel and ARM execution where
available. Do not disable Metal, weaken readiness checks or use an unbounded
wait to obtain a green job.

## Version before artifact staging

Read the shared version action: this repository's action invokes `npm version`
and pushes the semantic version bump. That operation requires a clean tracked
checkout. Stage freshly built binaries only AFTER versioning; replacing tracked
binaries first makes `npm version` fail with "Git working directory not clean".

Apply ordering fixes to BOTH hosted and self-hosted paths. The source-build
prerequisite must still succeed, and fresh same-run artifacts must still be
staged before the component is built. Do not bypass the clean-tree check with
force flags or commit generated binaries to work around the ordering.

## Compiler status is not a warning count

Unknown-class diagnostics such as 550.4 can be warnings. A local tool4d
20.7.101905 compile without resolved component definitions reported them and
still returned `Compile project...success`, producing compiled output.
Do not infer fatal failure, runtime failure or required dependency rewrites
from those warnings alone.

Inspect the compiler result's success and per-diagnostic `isError` severity.
In this session, the independently reproduced fatal errors were instead a
quoted object-literal header key and unsupported HTTPRequest equality in
`_Download`. See `4d-http-download` for those compatibility details.

The inspected shared `build-component@v1` helper called `Compile project`,
printed failure and then continued packaging, returning a successful process
exit. Its green action status therefore did not establish compile success.
Reinspect the shared implementation when applying this lesson: it may change.

## Verify the delivered format, not a guessed filename

Download and inspect the actual published asset. Compare its format with a
known successful compilation of the SAME tool version and targets; compiled
payload need not be a standalone `.4DC`.

For the successful local tool4d 20.7 dual-target build, the standard-ZIP
`.4DZ` contained nonempty `Project/DerivedData/CompiledCode/` entries such as
`MX64 ...`, `IX64 ...`, `classes.json` and `map.json`. The separate
`Libraries/lib4d-arm64.dylib` was also copied into the `.4dbase`.
An empty CompiledCode directory alone is not compiled payload. Do not turn
these observed names into an unverified rule for other 4D versions/targets.

For a future fail-closed gate, require explicit compiler success and appropriate
fresh target payload before signing/publication. Prevent stale self-hosted
outputs from satisfying the gate. This is a recommended check, not a claim that
such a gate is already implemented in this repository.

## Publication evidence and limits

Build success, compiler success, signed/notarized packaging, published release
existence and application runtime behavior are separate claims.

Verify non-draft status, intended prerelease/latest settings, expected ZIP/DMG
assets and downloaded hashes. Check source provenance for both native platforms,
Windows dependency closure and executable hashes, Mac architectures, executable
modes, signatures and actual notarization status. Signing changes executable
hashes; compare the appropriate pre-sign or post-sign identity. "Accepted"
notarization does not itself prove a stapled offline ticket.

Exercise the released native executable and helper where feasible, and state
when real 4D callbacks, Windows runtime or model inference were not executed.
Do not download large model weights just to verify release layout.

Never delete/overwrite existing tags or assets to conceal a defective release.
With authorization, add a precise warning based on confirmed evidence, preserve
existing notes, and prevent it being recommended as latest when supported.
Do not claim an observed user runtime failure when only compiler/package
evidence exists. Do not promise or dispatch a replacement after a user asks to
stop. A green workflow or published asset is not grounds to declare a remaining
release defect fixed.

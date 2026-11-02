#!/usr/bin/env python3
"""Build upstream executables and stage a self-contained 4D resource directory."""

import argparse
import hashlib
import json
import os
from pathlib import Path
import platform
import shutil
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[1]
LOCK = ROOT / "scripts/upstream.json"


def pe_dependencies(path):
    data = path.read_bytes()
    if data[:2] != b"MZ":
        raise RuntimeError(f"Not a PE executable: {path}")
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe:pe + 4] != b"PE\0\0":
        raise RuntimeError(f"Invalid PE signature: {path}")
    machine, section_count = struct.unpack_from("<HH", data, pe + 4)
    optional_size = struct.unpack_from("<H", data, pe + 20)[0]
    optional = pe + 24
    if struct.unpack_from("<H", data, optional)[0] != 0x20B:
        raise RuntimeError(f"Expected a PE32+ executable: {path}")
    import_rva, import_size = struct.unpack_from("<II", data, optional + 120)
    sections = []
    for index in range(section_count):
        offset = optional + optional_size + index * 40
        virtual_size, rva, size, raw = struct.unpack_from("<IIII", data, offset + 8)
        sections.append((rva, virtual_size, raw, size))

    def file_offset(rva):
        for start, virtual_size, raw, size in sections:
            relative = rva - start
            if 0 <= relative < max(virtual_size, size):
                if relative >= size or raw + relative >= len(data):
                    break
                return raw + relative
        raise RuntimeError(f"Invalid import RVA in {path}: {rva}")

    imports = []
    if import_rva:
        descriptor = file_offset(import_rva)
        end = min(descriptor + import_size, len(data))
        while descriptor + 20 <= end:
            entry = struct.unpack_from("<IIIII", data, descriptor)
            if not any(entry):
                return machine, sorted(set(imports))
            name_offset = file_offset(entry[3])
            name_end = data.find(b"\0", name_offset, name_offset + 256)
            if name_end < 0:
                raise RuntimeError(f"Invalid import name in {path}")
            imports.append(data[name_offset:name_end].decode("ascii").upper())
            descriptor += 20
        raise RuntimeError(f"Unterminated import table in {path}")
    return machine, imports


def audit_windows(path):
    machine, imports = pe_dependencies(path)
    if machine != 0x8664:
        raise RuntimeError(f"Expected Windows x64, got PE machine {machine:#x}: {path}")
    system = {
        "KERNEL32.DLL", "SHELL32.DLL", "ADVAPI32.DLL", "WS2_32.DLL", "BCRYPT.DLL",
        "USER32.DLL", "NTDLL.DLL", "OLE32.DLL", "CRYPT32.DLL", "SECUR32.DLL",
        "IPHLPAPI.DLL", "USERENV.DLL",
    }
    # Upstream libwebm selects the DLL CRT; preserve the existing VC++ runtime prerequisite.
    crt = {
        "MSVCP140.DLL", "MSVCP140_1.DLL", "MSVCP140_2.DLL",
        "MSVCP140_CODECVT_IDS.DLL", "MSVCP140_ATOMIC_WAIT.DLL",
        "VCRUNTIME140.DLL", "VCRUNTIME140_1.DLL", "CONCRT140.DLL",
    }
    unexpected = [name for name in imports if name not in system | crt
                  and not name.startswith(("API-MS-WIN-", "EXT-MS-WIN-"))]
    if unexpected:
        raise RuntimeError(f"Unpackaged Windows dependencies in {path}: {unexpected}")
    return imports


def run(*args, capture=False, cwd=None):
    print("+", " ".join(map(str, args)), flush=True)
    result = subprocess.run(
        list(map(str, args)), check=True, cwd=cwd,
        stdout=subprocess.PIPE if capture else None, text=True,
    )
    return result.stdout.strip() if capture else None


def cmake_options(system, arch, backend):
    options = [
        "-DCMAKE_BUILD_TYPE=Release",
        "-DSD_BUILD_EXAMPLES=ON",
        "-DSD_SERVER_BUILD_FRONTEND=OFF",
        "-DSD_BUILD_SHARED_LIBS=OFF",
        "-DSD_BUILD_SHARED_GGML_LIB=OFF",
        "-DBUILD_SHARED_LIBS=OFF",
        "-DGGML_BACKEND_DL=OFF",
        "-DGGML_NATIVE=OFF",
        "-DGGML_OPENMP=OFF",
        "-DSD_WEBP=ON",
        "-DSD_WEBM=ON",
        f"-DSD_METAL={'ON' if backend == 'metal' else 'OFF'}",
        f"-DGGML_METAL={'ON' if backend == 'metal' else 'OFF'}",
    ]
    if system == "Darwin":
        options += [
            f"-DCMAKE_OSX_ARCHITECTURES={arch}",
            "-DCMAKE_OSX_DEPLOYMENT_TARGET=14.0",
            "-DGGML_METAL_EMBED_LIBRARY=ON",
        ]
    if arch == "x86_64":
        # Match the AVX2 baseline without specializing for the build machine.
        options += ["-DGGML_AVX=ON", "-DGGML_AVX2=ON",
                    "-DGGML_FMA=ON", "-DGGML_F16C=ON"]
    return options


def initialize_submodules(source):
    # Initialize the inference engine as well as media dependencies on fresh runners.
    # CUDA's CUTLASS and the disabled web frontend are not used by these packages.
    run("git", "-C", source, "submodule", "update", "--init", "--recursive",
        "--depth=1", "--", "ggml", "thirdparty/libwebp", "thirdparty/libwebm")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--ref", help="Upstream commit/tag to verify instead of the lock")
    parser.add_argument("--arch", choices=["native", "arm64", "x86_64", "universal"],
                        default="native")
    parser.add_argument("--backend", choices=["auto", "cpu", "metal"], default="auto")
    parser.add_argument("--work-dir", type=Path, default=ROOT / ".build")
    parser.add_argument("--output", type=Path,
                        help="Staging directory (default: .build/package/<platform>)")
    parser.add_argument("--jobs", type=int, default=min(os.cpu_count() or 2, 8))
    args = parser.parse_args()
    system = platform.system()
    if system not in ("Darwin", "Windows") or args.jobs < 1:
        parser.error("Use macOS or Windows and a positive --jobs count")
    host_arch = {"AMD64": "x86_64", "aarch64": "arm64"}.get(
        platform.machine(), platform.machine())
    arch = host_arch if args.arch == "native" else args.arch
    backend = ("metal" if system == "Darwin" else "cpu") if args.backend == "auto" else args.backend
    if system == "Windows" and (arch != "x86_64" or backend != "cpu"):
        parser.error("The Windows package supports x86_64/CPU only")
    if system == "Darwin" and arch not in ("arm64", "x86_64", "universal"):
        parser.error("Unsupported macOS architecture")
    lock = json.loads(LOCK.read_text())
    work = args.work_dir.resolve()
    source = work / "upstream"
    work.mkdir(parents=True, exist_ok=True)
    if not source.exists():
        run("git", "init", source)
        run("git", "-C", source, "remote", "add", "origin", lock["repository"])
    origin = run("git", "-C", source, "remote", "get-url", "origin", capture=True)
    if origin != lock["repository"]:
        parser.error(f"Unexpected upstream origin: {origin}")
    dirty = run("git", "-C", source, "status", "--porcelain",
                "--untracked-files=normal", capture=True)
    if dirty:
        parser.error("Upstream worktree is dirty; use a different --work-dir")
    ref = args.ref or lock["revision"]
    run("git", "-C", source, "fetch", "--depth=1", "origin", ref)
    run("git", "-C", source, "checkout", "--detach", "FETCH_HEAD")
    revision = run("git", "-C", source, "rev-parse", "HEAD", capture=True)
    if not args.ref and revision != lock["revision"]:
        raise RuntimeError("Fetched revision does not match the upstream lock")
    initialize_submodules(source)
    arches = ["arm64", "x86_64"] if arch == "universal" else [arch]
    platform_name = "macOS" if system == "Darwin" else "Windows"
    output = (args.output or work / "package" / platform_name).resolve()
    suffix = ".exe" if system == "Windows" else ""
    targets = ["sd-server", "sd-cli", "sd-cache"]
    builds = {}
    configs = {}
    for slice_arch in arches:
        build = work / f"build-{revision[:12]}-{slice_arch}-{backend}"
        options = cmake_options(system, slice_arch, backend)
        generator = ["-G", "Visual Studio 17 2022", "-A", "x64"] if system == "Windows" else ["-G", "Ninja"]
        run("cmake", "-S", source, "-B", build, *generator, *options)
        run("cmake", "--build", build, "--config", "Release", "--parallel",
            args.jobs, "--target", "sd-server", "sd-cli")
        cache_build = work / f"cache-{slice_arch}"
        cache_options = [
            "-DCMAKE_BUILD_TYPE=Release",
            f"-DSD_JSON_INCLUDE_DIR={source / 'thirdparty'}",
        ]
        if system == "Darwin":
            cache_options += [f"-DCMAKE_OSX_ARCHITECTURES={slice_arch}",
                              "-DCMAKE_OSX_DEPLOYMENT_TARGET=14.0"]
        run("cmake", "-S", ROOT / "native/cache", "-B", cache_build, *generator, *cache_options)
        run("cmake", "--build", cache_build, "--config", "Release", "--parallel", args.jobs)
        bin_dir = build / "bin" / ("Release" if system == "Windows" else "")
        cache_bin = cache_build / ("Release" if system == "Windows" else "")
        builds[slice_arch] = {
            "sd-server": bin_dir / ("sd-server" + suffix),
            "sd-cli": bin_dir / ("sd-cli" + suffix),
            "sd-cache": cache_bin / ("sd-cache" + suffix),
        }
        configs[slice_arch] = options
    output.mkdir(parents=True, exist_ok=True)
    runtime_dependencies = {}
    for target in targets:
        destination = output / (target + suffix)
        inputs = [builds[a][target] for a in arches]
        if arch == "universal":
            run("lipo", "-create", *inputs, "-output", destination)
        else:
            shutil.copy2(inputs[0], destination)
        if system == "Darwin":
            run("lipo", destination, "-verify_arch", *arches)
            destination.chmod(0o755)
            run("codesign", "--force", "--sign", "-", destination)
            run("codesign", "--verify", "--strict", destination)
            dependencies = run("otool", "-L", destination, capture=True)
            runtime_dependencies[target] = sorted({
                line.strip().split(" (")[0] for line in dependencies.splitlines()
                if "compatibility version" in line
            })
            for line in dependencies.splitlines():
                if "compatibility version" in line and not line.strip().startswith(("/usr/lib/", "/System/Library/")):
                    raise RuntimeError(f"Non-system dependency in package: {line}")
        else:
            runtime_dependencies[target + suffix] = audit_windows(destination)
    licenses = output / "licenses"
    licenses.mkdir(parents=True, exist_ok=True)
    shutil.copy2(ROOT / "LICENSE", licenses / "sd-cache-LICENSE")
    # Single-file dependencies carry their notices inside the distributed source.
    for path in (source / "thirdparty").iterdir():
        if path.is_file() and (path.suffix in (".h", ".hpp", ".c") or path.name == "README.md"):
            destination = licenses / path.relative_to(source)
            destination.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(path, destination)
    for base in (source / "LICENSE", source / "ggml" / "LICENSE", source / "thirdparty"):
        candidates = [base] if base.is_file() else base.rglob("*")
        for path in candidates:
            if path.is_file() and path.name.upper().startswith(("LICENSE", "COPYING", "NOTICE", "PATENTS", "AUTHORS")):
                # Exclude unused CUDA dependencies from the CPU/Metal package.
                relative = path.relative_to(source)
                if "cutlass" not in relative.parts:
                    destination = licenses / relative
                    destination.parent.mkdir(parents=True, exist_ok=True)
                    shutil.copy2(path, destination)
    hashes = {target + suffix: hashlib.sha256((output / (target + suffix)).read_bytes()).hexdigest()
              for target in targets}
    provenance = {
        "repository": lock["repository"], "revision": revision,
        "committed_at": run("git", "-C", source, "show", "-s", "--format=%cI", "HEAD", capture=True),
        "requested_ref": ref, "platform": platform_name, "architecture": arch,
        "backend": backend, "cmake_options": configs,
        "cmake_version": run("cmake", "--version", capture=True).splitlines()[0],
        "runtime_dependencies": runtime_dependencies,
        "component_revision": run("git", "-C", ROOT, "rev-parse", "HEAD", capture=True),
        "build_script_sha256": hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        "cache_helper_sha256": hashlib.sha256((ROOT / "native/cache/main.cpp").read_bytes()).hexdigest(),
        "cache_cmake_sha256": hashlib.sha256((ROOT / "native/cache/CMakeLists.txt").read_bytes()).hexdigest(),
        "hash_scope": "Source-build artifacts after local signing; downstream release signing may change executable bytes",
        "submodules": run("git", "-C", source, "submodule", "status", capture=True).splitlines(),
        "sha256": hashes,
    }
    (output / "build-info.json").write_text(json.dumps(provenance, indent=2) + "\n")
    run(os.sys.executable, ROOT / "scripts/smoke-server.py", output / ("sd-server" + suffix))
    run(output / ("sd-server" + suffix), "--list-devices")
    run(output / ("sd-cli" + suffix), "--help")
    print(f"Package ready: {output}", flush=True)


if __name__ == "__main__":
    main()

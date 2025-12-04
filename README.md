# stable-diffusion
Local inference engine

#### Apple Silicon

```
git clone --recursive https://github.com/leejet/stable-diffusion.cpp
cd stable-diffusion.cpp
cmake -S . -B build_arm 
cmake --build build_arm --config Release
```

#### Intel

```
git clone --recursive https://github.com/leejet/stable-diffusion.cpp
cd stable-diffusion.cpp
cmake -S . -B build_amd 
cmake --build build_amd --config Release
```

#### Windows

```
git clone --recursive https://github.com/leejet/stable-diffusion.cpp
cd stable-diffusion.cpp
cmake -A x64 -S . -B build
cmake --build build --config Release
```

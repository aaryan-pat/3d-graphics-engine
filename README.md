# WIP Software Rendering Engine

Planning to be a high performance 3D graphics engine built from scratch in C++, implementing a complete software rendering pipeline with a focus on optimization for embedded systems and graphics hardware design

## Build

### Prerequisites
- CMake 3.16+
- C++17 compiler (MSVC, GCC, or Clang)

### Windows (Visual Studio)
```bash
mkdir build
cd build
cmake -G "Visual Studio 17 2022" ..
cmake --build . --config Release
```

### Linux/macOS
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

## Performance Notes

- **Optimization Flags**: AVX2 (SIMD), fast-math, O3 optimizations enabled by default
- **Memory Layout**: Structure-of-Arrays (SoA) optimization opportunities for batch transforms
- **Profiling**: Use Visual Studio Performance Profiler or `perf`
# Engine3D - Software Rendering Engine

A high-performance 3D graphics engine built from scratch in C++, implementing a complete software rendering pipeline with a focus on optimization for embedded systems and graphics hardware design.

## Architecture

### Math Foundation (`src/math/`)
- **vector.h/cpp**: Vector2, Vector3, Vector4 operations with SIMD-ready layout
- **matrix.h/cpp**: Matrix4x4 transformations (translation, rotation, scale, perspective, lookAt)

### Renderer Pipeline (`src/renderer/`)
- **rasterizer.h**: Triangle rasterization with scan-line algorithm
- **depth_buffer.h**: Z-buffering for visibility determination
- **texture.h**: Perspective-correct texture interpolation via barycentric coordinates

### Geometry (`src/geometry/`)
- **mesh.h**: Vertex/triangle mesh representation
- **obj_loader.h**: OBJ file parsing and mesh loading

## Key Features (Planned)

- [x] **Math Foundation**: Vectors, matrices, transforms
- [ ] **Software Rasterizer**: Scan-line triangle fill with clipping
- [ ] **Depth Buffering**: Z-order visibility
- [ ] **Back-face Culling**: Normal-based face removal
- [ ] **OBJ Mesh Loading**: Parse .obj files
- [ ] **Texture Mapping**: Perspective-correct interpolation
- [ ] **Performance Optimizations**: SIMD, cache tuning, profiling

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
- **Profiling**: Use Visual Studio Performance Profiler or `perf` on Linux

## Next Steps

Phase 1 ✓ - Math Foundation  
Phase 2 - Basic Rasterizer + Wireframe Rendering  
Phase 3 - Depth Buffering + Back-face Culling  
Phase 4 - OBJ Loader + Mesh Processing  
Phase 5 - Texture Mapping + Perspective Correction  
Phase 6 - Performance Tuning & SIMD Optimization  

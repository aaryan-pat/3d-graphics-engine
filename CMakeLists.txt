cmake_minimum_required(VERSION 3.16)
project(Engine3D CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optimization flags
if(MSVC)
    add_compile_options(/O2 /arch:AVX2 /fp:fast)
else()
    add_compile_options(-O3 -march=native -ffast-math)
endif()

# Main executable
add_executable(engine3d
    src/main.cpp
    src/math/vector.cpp
    src/math/matrix.cpp
)

target_include_directories(engine3d PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Enable SIMD intrinsics
if(MSVC)
    target_compile_options(engine3d PRIVATE /arch:AVX2)
else()
    target_compile_options(engine3d PRIVATE -march=native)
endif()

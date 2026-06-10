#include <iostream>
#include "math/vector.h"
#include "math/matrix.h"

int main() {
    std::cout << "=== Engine3D: Math Foundation ===\n\n";

    // Test Vector3 operations
    Vector3 v1(1, 2, 3);
    Vector3 v2(4, 5, 6);
    std::cout << "Vector3 Addition: (" << (v1 + v2).x << ", "
              << (v1 + v2).y << ", " << (v1 + v2).z << ")\n";
    std::cout << "Vector3 Dot Product: " << v1.dot(v2) << "\n";
    std::cout << "Vector3 Cross Product: (" << v1.cross(v2).x << ", "
              << v1.cross(v2).y << ", " << v1.cross(v2).z << ")\n";

    // Test Matrix operations
    Matrix4x4 translation = Matrix4x4::translation(5, 10, 15);
    Matrix4x4 scale = Matrix4x4::scale(2, 2, 2);
    Matrix4x4 combined = translation * scale;

    Vector4 point(1, 1, 1, 1);
    Vector4 transformed = combined * point;
    std::cout << "\nTransformed point: (" << transformed.x << ", "
              << transformed.y << ", " << transformed.z << ")\n";

    // Test camera transforms
    Vector3 eye(0, 0, -5);
    Vector3 center(0, 0, 0);
    Vector3 up(0, 1, 0);
    Matrix4x4 view = Matrix4x4::lookAt(eye, center, up);

    Matrix4x4 projection = Matrix4x4::perspective(
        3.14159f / 4.0f,  // 45 degree FOV
        1.0f,             // aspect ratio
        0.1f,             // near
        100.0f            // far
    );

    std::cout << "\nCamera setup complete (perspective + view matrices)\n";
    std::cout << "Ready for rasterizer implementation.\n";

    return 0;
}

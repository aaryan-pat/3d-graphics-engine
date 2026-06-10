#pragma once
#include <cmath>
#include <array>

struct Vector3 {
    float x, y, z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3& v) const {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    Vector3 operator-(const Vector3& v) const {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    Vector3 operator*(float s) const {
        return Vector3(x * s, y * s, z * s);
    }

    Vector3 operator/(float s) const {
        float inv = 1.0f / s;
        return Vector3(x * inv, y * inv, z * inv);
    }

    float dot(const Vector3& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    Vector3 cross(const Vector3& v) const {
        return Vector3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }

    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3 normalize() const {
        return *this / length();
    }
};

struct Vector4 {
    float x, y, z, w;

    Vector4() : x(0), y(0), z(0), w(1) {}
    Vector4(float x, float y, float z, float w = 1.0f) : x(x), y(y), z(z), w(w) {}
    Vector4(const Vector3& v, float w = 1.0f) : x(v.x), y(v.y), z(v.z), w(w) {}

    Vector3 xyz() const {
        return Vector3(x, y, z);
    }
};

struct Vector2 {
    float x, y;

    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}

    Vector2 operator+(const Vector2& v) const {
        return Vector2(x + v.x, y + v.y);
    }

    Vector2 operator-(const Vector2& v) const {
        return Vector2(x - v.x, y - v.y);
    }

    Vector2 operator*(float s) const {
        return Vector2(x * s, y * s);
    }

    float dot(const Vector2& v) const {
        return x * v.x + y * v.y;
    }
};

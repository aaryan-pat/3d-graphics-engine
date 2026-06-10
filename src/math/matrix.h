#pragma once
#include "vector.h"
#include <cstring>

struct Matrix4x4 {
    float m[16];

    Matrix4x4() {
        std::memset(m, 0, sizeof(m));
    }

    static Matrix4x4 identity() {
        Matrix4x4 mat;
        mat.m[0] = mat.m[5] = mat.m[10] = mat.m[15] = 1.0f;
        return mat;
    }

    static Matrix4x4 translation(float x, float y, float z) {
        Matrix4x4 mat = identity();
        mat.m[12] = x;
        mat.m[13] = y;
        mat.m[14] = z;
        return mat;
    }

    static Matrix4x4 scale(float x, float y, float z) {
        Matrix4x4 mat = identity();
        mat.m[0] = x;
        mat.m[5] = y;
        mat.m[10] = z;
        return mat;
    }

    static Matrix4x4 rotationX(float angle) {
        Matrix4x4 mat = identity();
        float c = std::cos(angle);
        float s = std::sin(angle);
        mat.m[5] = c;
        mat.m[6] = -s;
        mat.m[9] = s;
        mat.m[10] = c;
        return mat;
    }

    static Matrix4x4 rotationY(float angle) {
        Matrix4x4 mat = identity();
        float c = std::cos(angle);
        float s = std::sin(angle);
        mat.m[0] = c;
        mat.m[2] = s;
        mat.m[8] = -s;
        mat.m[10] = c;
        return mat;
    }

    static Matrix4x4 rotationZ(float angle) {
        Matrix4x4 mat = identity();
        float c = std::cos(angle);
        float s = std::sin(angle);
        mat.m[0] = c;
        mat.m[1] = -s;
        mat.m[4] = s;
        mat.m[5] = c;
        return mat;
    }

    static Matrix4x4 perspective(float fov, float aspect, float near, float far) {
        Matrix4x4 mat;
        float f = 1.0f / std::tan(fov / 2.0f);
        mat.m[0] = f / aspect;
        mat.m[5] = f;
        mat.m[10] = (far + near) / (near - far);
        mat.m[11] = -1.0f;
        mat.m[14] = (2.0f * far * near) / (near - far);
        return mat;
    }

    static Matrix4x4 lookAt(Vector3 eye, Vector3 center, Vector3 up) {
        Vector3 f = (center - eye).normalize();
        Vector3 s = f.cross(up).normalize();
        Vector3 u = s.cross(f);

        Matrix4x4 mat = identity();
        mat.m[0] = s.x;
        mat.m[1] = u.x;
        mat.m[2] = -f.x;
        mat.m[4] = s.y;
        mat.m[5] = u.y;
        mat.m[6] = -f.y;
        mat.m[8] = s.z;
        mat.m[9] = u.z;
        mat.m[10] = -f.z;
        mat.m[12] = -s.dot(eye);
        mat.m[13] = -u.dot(eye);
        mat.m[14] = f.dot(eye);
        return mat;
    }

    Matrix4x4 operator*(const Matrix4x4& rhs) const {
        Matrix4x4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m[i * 4 + j] = 0;
                for (int k = 0; k < 4; k++) {
                    result.m[i * 4 + j] += m[i * 4 + k] * rhs.m[k * 4 + j];
                }
            }
        }
        return result;
    }

    Vector4 operator*(const Vector4& v) const {
        Vector4 result;
        result.x = m[0] * v.x + m[4] * v.y + m[8] * v.z + m[12] * v.w;
        result.y = m[1] * v.x + m[5] * v.y + m[9] * v.z + m[13] * v.w;
        result.z = m[2] * v.x + m[6] * v.y + m[10] * v.z + m[14] * v.w;
        result.w = m[3] * v.x + m[7] * v.y + m[11] * v.z + m[15] * v.w;
        return result;
    }

    Matrix4x4 transpose() const {
        Matrix4x4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m[j * 4 + i] = m[i * 4 + j];
            }
        }
        return result;
    }
};

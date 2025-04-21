/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#include "vector3.h"

Vector3f Vector3f::operator+(const Vector3f& v) const {
    return {
        x + v.x,
        y + v.y,
        z + v.z
    };
}

Vector3f Vector3f::operator-(const Vector3f& v) const {
    return {
        x - v.x,
        y - v.y,
        z - v.z
    };
}

Vector3f Vector3f::operator-() const {
    return {
        -x,
        -y,
        -z
    };
}

Vector3f Vector3f::operator*(Float a) const {
    return {
        x * a,
        y * a,
        z * a
    };
}

Vector3f Vector3f::operator/(Float a) const {
    return *this * ((Float)1.0 / a);
}

std::ostream& operator<<(std::ostream& os, const Vector3f& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

Vector3f operator*(Float a, const Vector3f& v) {
    return v * a;
}

Float dot(const Vector3f& u, const Vector3f& v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

Vector3f cross(const Vector3f& u, const Vector3f& v) {
    return {
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    };
}

Float norm(const Vector3f& v) {
    return std::sqrt(square_norm(v));
}

Float square_norm(const Vector3f& v) {
    return dot(v, v);
}

Vector3f unit(const Vector3f& v) {
    return v / norm(v);
}

Vector3f lerp(const Vector3f& u, const Vector3f& v, Float t) {
    return u + (v - u) * t;
}

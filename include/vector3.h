/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#ifndef _CS100_RAY_TRACING_VECTOR3_H_
#define _CS100_RAY_TRACING_VECTOR3_H_

#include <iostream>

#include "math-utils.h"

struct Vector3f {
    Float x, y, z;

    /// @brief u + v
    Vector3f operator+(const Vector3f& v) const;

    /// @brief u - v
    Vector3f operator-(const Vector3f& v) const;

    /// @brief -u
    Vector3f operator-() const;

    /// @brief u * a
    Vector3f operator*(Float a) const;

    /// @brief u / a
    Vector3f operator/(Float a) const;

    std::ostream& operator<<(std::ostream& os) const;
};

/// @brief a * u
Vector3f operator*(Float a, const Vector3f& v);

/// @brief u * v
Float dot(const Vector3f& u, const Vector3f& v);

/// @brief u x v
Vector3f cross(const Vector3f& u, const Vector3f& v);

/// @brief |u|
Float norm(const Vector3f& v);

/// @brief |u|^2
Float square_norm(const Vector3f& v);

/// @brief u / |u|
Vector3f unit(const Vector3f& v);

/// @brief (1 - t) * u + t * v = u + (v - u) * t
Vector3f lerp(const Vector3f& u, const Vector3f& v, Float t);

typedef Vector3f Color3f;
typedef Vector3f Point3f;

#endif // !_CS100_RAY_TRACING_VECTOR3_H_

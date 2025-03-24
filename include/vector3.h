/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#ifndef _CS100_RAY_TRACING_VECTOR3_H_
#define _CS100_RAY_TRACING_VECTOR3_H_

#include "math-utils.h"

typedef struct Vector3f {
    Float x, y, z;
} Vector3f;

/// @brief u + v
Vector3f vector3_add(Vector3f u, Vector3f v);

/// @brief u - v
Vector3f vector3_sub(Vector3f u, Vector3f v);

/// @brief -u
Vector3f vector3_neg(Vector3f u);

/// @brief u * a
Vector3f vector3_scalar_mul(Vector3f u, Float a);

/// @brief u / a
Vector3f vector3_scalar_div(Vector3f u, Float a);

/// @brief u * v
Float vector3_dot(Vector3f u, Vector3f v);

/// @brief u x v
Vector3f vector3_cross(Vector3f u, Vector3f v);

/// @brief |u|
Float vector3_norm(Vector3f u);

/// @brief |u|^2
Float vector3_square_norm(Vector3f u);

/// @brief u / |u|
Vector3f vector3_unit(Vector3f u);

/// @brief (1 - t) * u + t * v = u + (v - u) * t
Vector3f vector3_lerp(Vector3f u, Vector3f v, Float t);

void vector3_print(Vector3f u);

typedef Vector3f Color3f;
typedef Vector3f Point3f;

#endif // !_CS100_RAY_TRACING_VECTOR3_H_

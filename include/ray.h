/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#ifndef _CS100_RAY_TRACING_RAY_H_
#define _CS100_RAY_TRACING_RAY_H_

#include "vector3.h"

typedef struct Ray {
    Vector3f origin;
    Vector3f direction;
} Ray;

Vector3f ray_at(Ray const* ray, Float t);

#endif // !_CS100_RAY_TRACING_RAY_H_

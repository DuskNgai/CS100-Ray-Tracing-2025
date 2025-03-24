/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#ifndef _CS100_RAY_TRACING_INTERACTION_H_
#define _CS100_RAY_TRACING_INTERACTION_H_

#include "vector3.h"

/// @brief The record for interaction between a ray and an object.
typedef struct Interaction {
    Float t;
    Point3f hit_point;
    Vector3f normal;
} Interaction;

#endif // !_CS100_RAY_TRACING_INTERACTION_H_

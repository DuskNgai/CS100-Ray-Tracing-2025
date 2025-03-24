/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#ifndef _CS100_RAY_TRACING_SPHERE_H_
#define _CS100_RAY_TRACING_SPHERE_H_

#include <stdbool.h>

#include "interaction.h"
#include "ray.h"

typedef struct Sphere {
    Point3f center;
    Float radius;
} Sphere;

bool sphere_hit(Sphere const* sphere, Ray const* ray, Float t_min, Float t_max, Interaction* interaction);

#endif // !_CS100_RAY_TRACING_SPHERE_H_

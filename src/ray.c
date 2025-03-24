/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#include "ray.h"

#include <assert.h>
#include <stddef.h>

Point3f ray_at(Ray const* r, Float t) {
    assert(r != NULL);

    return vector3_add(r->origin, vector3_scalar_mul(r->direction, t));
}

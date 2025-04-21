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

Point3f Ray::at(Float t) const {
    return this->origin + this->direction * t;
}

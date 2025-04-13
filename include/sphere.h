/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#ifndef _CS100_RAY_TRACING_SPHERE_H_
#define _CS100_RAY_TRACING_SPHERE_H_

#include "interaction.h"
#include "ray.h"

class Sphere {
public:
    Point3f center;
    Float radius;

public:
    Sphere(Point3f c, Float r);

public:
    bool hit(const Ray& ray, Float t_min, Float t_max, Interaction* interaction) const;
};


#endif // !_CS100_RAY_TRACING_SPHERE_H_

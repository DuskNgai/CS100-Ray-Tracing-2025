/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#include "sphere.h"

#include <cassert>
#include <cstddef>

Sphere::Sphere(Point3f c, Float r)
    : center(c)
    , radius(r) {}

bool Sphere::hit(Ray const& ray, Float t_min, Float t_max, Interaction* interaction) const {
    Vector3f oc = vector3_sub(ray.origin, this->center);

    // Convert to a quadratic equation.
    Float a = vector3_square_norm(ray.direction);
    Float b_half = vector3_dot(oc, ray.direction);
    Float c = vector3_square_norm(oc) - this->radius * this->radius;
    Float discriminant = b_half * b_half - a * c;

    if (discriminant < 0) {
        return false;
    }

    // Find and check the root.
    Float t = (-b_half - std::sqrt(discriminant)) / a;
    if (t < t_min || t > t_max) {
        t = (-b_half + std::sqrt(discriminant)) / a;
        if (t < t_min || t > t_max) {
            return false;
        }
    }

    // Record this interaction.
    interaction->t = t;
    interaction->hit_point = ray.at(t);
    interaction->normal = vector3_scalar_div(vector3_sub(interaction->hit_point, this->center), this->radius);
    return true;
}

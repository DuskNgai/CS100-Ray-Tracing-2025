/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#include <stdio.h>

#include "vector3.h"

Vector3f vector3_add(Vector3f u, Vector3f v) {
    return (Vector3f){
        u.x + v.x,
        u.y + v.y,
        u.z + v.z
    };
}


Vector3f vector3_sub(Vector3f u, Vector3f v) {
    return (Vector3f){
        u.x - v.x,
        u.y - v.y,
        u.z - v.z
    };
}


Vector3f vector3_neg(Vector3f u) {
    return (Vector3f){
        -u.x,
        -u.y,
        -u.z
    };
}

Vector3f vector3_scalar_mul(Vector3f u, Float a) {
    return (Vector3f){
        u.x * a,
        u.y * a,
        u.z * a
    };
}

Vector3f vector3_scalar_div(Vector3f u, Float a) {
    return vector3_scalar_mul(u, (Float)1.0 / a);
}

Float vector3_dot(Vector3f u, Vector3f v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

Vector3f vector3_cross(Vector3f u, Vector3f v) {
    return (Vector3f){
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    };
}

Float vector3_norm(Vector3f u) {
    return sqrt(vector3_square_norm(u));
}

Float vector3_square_norm(Vector3f u) {
    return vector3_dot(u, u);
}

Vector3f vector3_unit(Vector3f u) {
    return vector3_scalar_div(u, vector3_norm(u));
}

Vector3f vector3_lerp(Vector3f u, Vector3f v, Float t) {
    return vector3_add(u, vector3_scalar_mul(vector3_sub(u, v), t));
}

void vector3_print(Vector3f u) {
    printf("x: %f, y: %f, z: %f\n", u.x, u.y, u.z);
}

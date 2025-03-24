/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#include "renderer.h"

#include <assert.h>
#include <stddef.h>

#include "ray.h"

void render(Film* film, Sphere const* sphere) {
    assert(film != NULL);

    uint32_t image_width = film->width;
    uint32_t image_height = film->height;

    for (uint32_t y = 0; y < image_height; ++y) {
        for (uint32_t x = 0; x < image_width; ++x) {
            // Generate pixel aligned ray.
            Float u = (2.0f * x - image_width) / image_width;
            Float v = -(2.0f * y - image_height) / image_height;
            Float w = (Float)0.0;

            Ray ray = {(Vector3f){u, v, w}, (Vector3f){0.0f, 0.0f, -1.0f}};
            Interaction interaction;

            // Trace ray.
            if (sphere_hit(sphere, &ray, (Float)0.0, (Float)100.0, &interaction)) {
                // Store RGB color.
                film_set_pixel(film, x, y, vector3_scalar_div(vector3_add(interaction.normal, (Vector3f){1.0f, 1.0f, 1.0f}), (Float)2.0));
            }
            else {
                Float t = 0.5 * (-(Float)v - 1.0);
                film_set_pixel(film, x, y,vector3_lerp((Color3f){ 1.0, 1.0, 1.0 }, (Color3f){ 0.5, 0.7, 1.0 }, t));
            }
        }
    }
}

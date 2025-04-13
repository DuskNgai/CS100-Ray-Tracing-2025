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
#include <stdio.h>
#include <inttypes.h>

#include "ray.h"

void render(Camera* camera, Sphere const* sphere) {
    assert(camera != NULL);

    uint32_t image_width = camera->film->width;
    uint32_t image_height = camera->film->height;

    for (uint32_t y = 0; y < image_height; ++y) {
        printf("\rScanlines remaining: %" PRIu32 " ", image_height - y - 1);
        fflush(stdout);

        for (uint32_t x = 0; x < image_width; ++x) {
            Ray ray = camera_get_ray(camera, x, y);
            Color3f color = get_color(&ray, sphere);
            film_set_pixel(camera->film, x, y, color);
        }
    }
    printf("\nRendering complete.\n");
}

Color3f get_color(Ray const* ray, Sphere const* sphere) {
    Interaction interaction;

    // Trace ray.
    if (sphere_hit(sphere, ray, 0.0, 100.0, &interaction)) {
        return vector3_scalar_mul(vector3_add(interaction.normal, (Vector3f){ 1.0, 1.0, 1.0 }), 0.5);
    }
    else {
        Float t = 0.5 * (vector3_unit(ray->direction).y + 1.0);
        return vector3_lerp((Color3f){ 1.0, 1.0, 1.0 }, (Color3f){ 0.5, 0.7, 1.0 }, t);
    }
}

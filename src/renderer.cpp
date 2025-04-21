/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#include "renderer.h"

#include <cassert>
#include <cinttypes>
#include <cstddef>
#include <cstdio>

#include "ray.h"

void render(Camera& camera, Sphere const& sphere) {
    uint32_t image_width = camera.film->width;
    uint32_t image_height = camera.film->height;

    for (uint32_t y = 0; y < image_height; ++y) {
        std::printf("\rScanlines remaining: %" PRIu32 " ", image_height - y - 1);
        std::fflush(stdout);

        for (uint32_t x = 0; x < image_width; ++x) {
            Ray ray = camera.get_ray(x, y);
            Color3f color = get_color(ray, sphere);
            camera.film->set_pixel(x, y, color);
        }
    }
    std::printf("\nRendering complete.\n");
}

Color3f get_color(Ray const& ray, Sphere const& sphere) {
    Interaction interaction;

    // Trace ray.
    if (sphere.hit(ray, 0.0, 100.0, &interaction)) {
        return (interaction.normal + Vector3f{ 1.0, 1.0, 1.0 }) * 0.5;
    }
    else {
        Float t = 0.5 * (unit(ray.direction).y + 1.0);
        return lerp({ 1.0, 1.0, 1.0 }, { 0.5, 0.7, 1.0 }, t);
    }
}

/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>

#include "film.h"
#include "renderer.h"
#include "sphere.h"


int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::fprintf(stderr, "Usage: %s <image_width> <image_height> <output_file>\n", argv[0]);
        return 1;
    }

    uint32_t image_width = (uint32_t)strtoul(argv[1], NULL, 10);
    uint32_t image_height = (uint32_t)strtoul(argv[2], NULL, 10);
    if (image_width > 8192 or image_height > 8192) {
        std::fprintf(stderr, "Image sizes too large: %s x %s\n", argv[1], argv[2]);
        return 1;
    }
    std::printf("Rendering %" PRIu32 " x %" PRIu32 " image.\n", image_width, image_height);

    Film film(image_width, image_height);
    Camera camera(
        { 0.0, 0.0, 0.0 },
        { 0.0, 0.0, -1.0 },
        { 0.0, 1.0, 0.0 },
        M_PI_2,
        1.0,
        film.get_aspect_ratio()
    );
    camera.set_film(&film);
    Sphere sphere({ 0.0, 0.0, -1.0 }, 0.5);

    render(camera, sphere);
    film.save(argv[3]);

    return 0;
}

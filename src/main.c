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

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include "film.h"
#include "renderer.h"
#include "sphere.h"


int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image_width> <image_height> <output_file>\n", argv[0]);
        return 1;
    }

    uint32_t image_width = (uint32_t)strtoul(argv[1], NULL, 10);
    uint32_t image_height = (uint32_t)strtoul(argv[2], NULL, 10);
    if (image_width > 8192 || image_height > 8192) {
        fprintf(stderr, "Image sizes too large: %s x %s\n", argv[1], argv[2]);
        return 1;
    }
    printf("Rendering %" PRIu32 " x %" PRIu32 " image.\n", image_width, image_height);

    Film* film = film_create(image_width, image_height);
    Camera* camera = camera_create(
        (Point3f){ 0.0, 0.0, 0.0 },
        (Point3f){ 0.0, 0.0, -1.0 },
        (Vector3f){ 0.0, 1.0, 0.0 },
        M_PI_2,
        1.0,
        film_get_aspect_ratio(film)
    );
    camera_set_film(camera, film);
    Sphere sphere = { (Point3f){ 0.0, 0.0, -1.0 }, 0.5 };

    render(camera, &sphere);
    film_save(film, argv[3]);

    film_destroy(film);
    camera_destroy(camera);
    return 0;
}

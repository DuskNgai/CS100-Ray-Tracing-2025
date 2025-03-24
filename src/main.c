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


int main(void) {
    uint32_t image_width, image_height;
    scanf("%" PRIu32 "%" PRIu32, &image_width, &image_height);

    Film* film = film_create(image_width, image_height);
    Sphere sphere = {(Point3f){0.0f, 0.0f, -1.0f}, 0.5f};

    render(film, &sphere);
    film_save(film);

    film_destroy(film);
    return 0;
}

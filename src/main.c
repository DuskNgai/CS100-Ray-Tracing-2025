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


int main(void) {
    uint32_t image_width, image_height;
    scanf("%" PRIu32 "%" PRIu32, &image_width, &image_height);

    Float* film = (Float*)malloc((image_width * image_height * 3) * sizeof(Float));
    assert(film != NULL);

    render(film, image_width, image_height);
    save(film, image_width, image_height);

    free(film);
    return 0;
}

void render(Float* film, uint32_t image_width, uint32_t image_height) {
    for (uint32_t y = 0; y < image_height; ++y) {
        for (uint32_t x = 0; x < image_width; ++x) {
            // Initialize z and c.
            Float z_real = 0, z_imag = 0;
            Float c_real = (2.0 * x + 1.0) / (Float)image_width - 1.5;
            Float c_imag = (2.0 * y + 1.0) / (Float)image_height - 1.0;

            // Perform the Mandelbrot algorithm, z = z^2 + c.
            uint32_t num_iter = 0, max_iter = 2048;
            while (z_real * z_real + z_imag * z_imag <= 4 && num_iter < max_iter) {
                Float z_real_new = z_real * z_real - z_imag * z_imag + c_real;
                Float z_imag_new = 2 * z_real * z_imag + c_imag;
                z_real = z_real_new;
                z_imag = z_imag_new;
                ++num_iter;
            }

            // Output RGB color.
            Float r = 0.0, g = 0.0, b = 0.0;
            if (num_iter != max_iter) {
                // [1, max_iter] -> [0.0, 1.0]
                Float t = log((Float)num_iter) / log((Float)max_iter);
                r = t;
                g = t;
                b = 0.5 - 0.5 * t;
            }

            // Store RGB color.
            film[(y * image_width + x) * 3 + 0] = r;
            film[(y * image_width + x) * 3 + 1] = g;
            film[(y * image_width + x) * 3 + 2] = b;
        }
    }
}

void save(Float* film, uint32_t image_width, uint32_t image_height) {
    // Output PPM header.
    printf("P3\n%" PRIu32 " %" PRIu32 "\n255\n", image_width, image_height);

    for (uint32_t y = 0; y < image_height; ++y) {
        for (uint32_t x = 0; x < image_width; ++x) {
            // Read RGB color.
            Float r = film[(y * image_width + x) * 3 + 0];
            Float g = film[(y * image_width + x) * 3 + 1];
            Float b = film[(y * image_width + x) * 3 + 2];

            // [0.0, 1.0] -> [0, 255]
            uint8_t ir = (uint8_t)(r * 255.0);
            uint8_t ig = (uint8_t)(g * 255.0);
            uint8_t ib = (uint8_t)(b * 255.0);

            // Output RGB color.
            printf("%" PRIu8 " %" PRIu8 " %" PRIu8 "\n", ir, ig, ib);
        }
    }
}

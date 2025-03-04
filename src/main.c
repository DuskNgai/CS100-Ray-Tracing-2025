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

#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

void render(uint32_t image_width, uint32_t image_height);

int main(void) {
    uint32_t image_width, image_height;
    scanf("%" PRIu32 "%" PRIu32, &image_width, &image_height);
    printf("P3\n%" PRIu32 " %" PRIu32 "\n255\n", image_width, image_height);

    render(image_width, image_height);
    return 0;
}

void render(uint32_t image_width, uint32_t image_height) {
    for (uint32_t y = 0; y < image_height; ++y) {
        for (uint32_t x = 0; x < image_width; ++x) {
            // Initialize z and c.
            double z_real = 0, z_imag = 0;
            double c_real = (2.0 * x + 1.0) / (double)image_width - 1.5;
            double c_imag = (2.0 * y + 1.0) / (double)image_height - 1.0;

            // Perform the Mandelbrot algorithm, z = z^2 + c.
            uint32_t num_iter = 0, max_iter = 2048;
            while (z_real * z_real + z_imag * z_imag <= 4 && num_iter < max_iter) {
                double z_real_new = z_real * z_real - z_imag * z_imag + c_real;
                double z_imag_new = 2 * z_real * z_imag + c_imag;
                z_real = z_real_new;
                z_imag = z_imag_new;
                ++num_iter;
            }

            // Output RGB color.
            if (num_iter == max_iter) {
                printf("0 0 0\n");
            }
            else {
                // [1, max_iter] -> [0.0, 1.0]
                double t = log((double)num_iter) / log((double)max_iter);
                double r = t;
                double g = t;
                double b = 0.5 - 0.5 * t;

                // [0.0, 1.0] -> [0, 255]
                uint8_t ir = (uint8_t)(255.0 * r);
                uint8_t ig = (uint8_t)(255.0 * g);
                uint8_t ib = (uint8_t)(255.0 * b);

                printf("%" PRIu8 " %" PRIu8 " %" PRIu8 "\n", ir, ig, ib);
            }
        }
    }
}

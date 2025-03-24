/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#include "film.h"

#include <assert.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

Film* film_create(uint32_t width, uint32_t height) {
    Film* film = (Film*)malloc(sizeof(Film));
    assert(film != NULL);

    film->width = width;
    film->height = height;
    film->pixels = (Color3f*)calloc(width * height, sizeof(Color3f));
    assert(film->pixels != NULL);

    return film;
}

void film_destroy(Film* film) {
    free(film->pixels);
    free(film);
}

Color3f film_get_pixel(Film const* film, uint32_t x, uint32_t y) {
    assert(x < film->width && y < film->height);
    return film->pixels[y * film->width + x];
}

void film_set_pixel(Film const* film, uint32_t x, uint32_t y, Color3f color) {
    assert(x < film->width && y < film->height);
    film->pixels[y * film->width + x] = color;
}

void film_save(Film const* film) {
    uint32_t image_width = film->width;
    uint32_t image_height = film->height;

    // Output PPM header.
    printf("P3\n%" PRIu32 " %" PRIu32 "\n255\n", image_width, image_height);

    for (uint32_t y = 0; y < image_height; ++y) {
        for (uint32_t x = 0; x < image_width; ++x) {
            // Read RGB color.
            Color3f color = film_get_pixel(film, x, y);

            // [0.0, 1.0] -> [0, 255]
            uint8_t ir = (uint8_t)(color.x * 255.0);
            uint8_t ig = (uint8_t)(color.y * 255.0);
            uint8_t ib = (uint8_t)(color.z * 255.0);

            // Output RGB color.
            printf("%" PRIu8 " %" PRIu8 " %" PRIu8 "\n", ir, ig, ib);
        }
    }
}

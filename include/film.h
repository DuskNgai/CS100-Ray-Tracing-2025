/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#ifndef _CS100_RAY_TRACING_FILM_H_
#define _CS100_RAY_TRACING_FILM_H_

#include <stdint.h>

#include "vector3.h"

typedef struct Film {
    uint32_t width;
    uint32_t height;
    Color3f* pixels;
} Film;

Film* film_create(uint32_t width, uint32_t height);

void film_destroy(Film* film);

Color3f film_get_pixel(Film const* film, uint32_t x, uint32_t y);

void film_set_pixel(Film const* film, uint32_t x, uint32_t y, Color3f color);

void film_save(Film const* film);

#endif // !_CS100_RAY_TRACING_FILM_H_

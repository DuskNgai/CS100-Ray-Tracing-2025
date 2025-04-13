/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#ifndef _CS100_RAY_TRACING_FILM_H_
#define _CS100_RAY_TRACING_FILM_H_

#include <cstdint>
#include <string>
#include <vector>

#include "vector3.h"

class Film {
public:
    uint32_t width;
    uint32_t height;
    std::vector<Color3f> pixels;

public:
    Film(uint32_t width, uint32_t height);

public:
    Color3f get_pixel(uint32_t x, uint32_t y) const;
    void set_pixel(uint32_t x, uint32_t y, Color3f color);

    /// @brief Get the aspect ratio of the film.
    Float get_aspect_ratio() const;

    /// @brief Save the image in film to filename.
    void save(std::string const& filename) const;
};


#endif // !_CS100_RAY_TRACING_FILM_H_

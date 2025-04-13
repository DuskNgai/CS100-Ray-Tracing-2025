/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#include "film.h"

#include <cassert>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

Film::Film(uint32_t width, uint32_t height)
    : width(width)
    , height(height)
    , pixels(width * height) {}

Color3f Film::get_pixel(uint32_t x, uint32_t y) const {
    assert(x < width && y < height);
    return pixels[y * width + x];
}

void Film::set_pixel(uint32_t x, uint32_t y, Color3f color) {
    assert(x < width && y < height);
    pixels[y * width + x] = color;
}

Float Film::get_aspect_ratio() const {
    return static_cast<Float>(width) / static_cast<Float>(height);
}

void Film::save(std::string const& filename) const {
    FILE* file = std::fopen(filename.c_str(), "w");
    assert(file != nullptr);

    // Output PPM header.
    std::fprintf(file, "P3\n%" PRIu32 " %" PRIu32 "\n255\n", width, height);
    for (uint32_t y = 0; y < height; ++y) {
        for (uint32_t x = 0; x < width; ++x) {
            // Read RGB color.
            Color3f color = get_pixel(x, y);

            // [0.0, 1.0] -> [0, 255]
            uint8_t ir = static_cast<uint8_t>(color.x * 255.0);
            uint8_t ig = static_cast<uint8_t>(color.y * 255.0);
            uint8_t ib = static_cast<uint8_t>(color.z * 255.0);

            // Output RGB color.
            std::fprintf(file, "%" PRIu8 " %" PRIu8 " %" PRIu8 "\n", ir, ig, ib);
        }
    }

    // Close the file.
    std::fclose(file);
}

/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#include "camera.h"

#include <cassert>
#include <cstddef>
#include <cstdlib>

Camera::Camera(Vector3f look_from, Vector3f look_to, Vector3f ref_up, Float y_fov, Float focal_length, Float aspect_ratio)
    : look_from(look_from)
    , look_to(look_to)
    , ref_up(ref_up)
    , y_fov(y_fov)
    , focal_length(focal_length)
    , aspect_ratio(aspect_ratio)
    , film(nullptr) {
    // Compute the camera coordinate system.
    this->look_front = unit(look_to - look_from);
    this->look_right = unit(cross(this->look_front, ref_up));
    this->look_up = unit(cross(this->look_right, this->look_front));

    // Compute the camera frame.
    this->vertical = this->look_up * (std::tan(y_fov * (Float)0.5) * focal_length);
    this->horizontal = this->look_right * (aspect_ratio * norm(this->vertical));
}

void Camera::set_film(Film* film) {
    assert(film != nullptr);
    this->film = film;
}

Ray Camera::get_ray(uint32_t x, uint32_t y) const {
    assert(this->film != nullptr);

    // Instead of shooting ray to the corner of the pixel,
    // we shoot ray to the center of the pixel (x + 0.5, y + 0.5).
    Float u = (2.0 * ((Float)x + 0.5) / (Float)this->film->width) - 1.0;
    Float v = (2.0 * ((Float)y + 0.5) / (Float)this->film->height) - 1.0;

    Point3f origin = look_from;
    Point3f direction = this->horizontal * u + this->vertical * (-v) + this->look_front * this->focal_length;

    return Ray{ origin, direction };
}

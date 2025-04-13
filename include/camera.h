/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#ifndef _CS100_RAY_TRACING_CAMERA_H_
#define _CS100_RAY_TRACING_CAMERA_H_

#include "film.h"
#include "ray.h"

class Camera {
public:
    Point3f look_from;
    Point3f look_to;
    Vector3f ref_up;

    Float y_fov;
    Float focal_length;
    Float aspect_ratio;

    Vector3f look_front;
    Vector3f look_right;
    Vector3f look_up;

    Vector3f horizontal;
    Vector3f vertical;

    Film* film;

public:
    Camera(Point3f look_from, Point3f look_to, Vector3f ref_up, Float y_fov, Float focal_length, Float aspect_ratio);

public:
    void set_film(Film* film);
    void set_pixel(uint32_t x, uint32_t y, Color3f color);

    /// @brief Get a ray from the camera to the pixel (x, y).
    Ray get_ray(uint32_t x, uint32_t y) const;
};

#endif // !_CS100_RAY_TRACING_CAMERA_H_

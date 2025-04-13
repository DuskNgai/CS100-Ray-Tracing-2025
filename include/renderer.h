/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#ifndef _CS100_RAY_TRACING_RENDERER_H_
#define _CS100_RAY_TRACING_RENDERER_H_

#include <stdint.h>

#include "camera.h"
#include "sphere.h"

void render(Camera* camera, Sphere const* sphere);

Color3f get_color(Ray const* ray, Sphere const* sphere);

#endif // !_CS100_RAY_TRACING_RENDERER_H_

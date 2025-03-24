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

#include "film.h"
#include "sphere.h"

void render(Film* film, Sphere const* sphere);

#endif // !_CS100_RAY_TRACING_RENDERER_H_

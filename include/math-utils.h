/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#ifndef _CS100_RAY_TRACING_MATH_UTILS_H_
#define _CS100_RAY_TRACING_MATH_UTILS_H_

#include <math.h>

typedef float Float;

// Generic selection, a c11 standard feature.
// https://en.cppreference.com/w/c/language/generic
// clang-format off
#define sqrt(x)            \
    _Generic((x),          \
        float: sqrtf,      \
        double: sqrt,      \
        long double: sqrtl \
    )(x)
// clang-format on

#endif // !_CS100_RAY_TRACING_MATH_UTILS_H_

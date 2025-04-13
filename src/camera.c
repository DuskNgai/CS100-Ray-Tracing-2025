/*
 * CS100-Ray-Tracing for course recitation.
 *
 * Copyright (C) 2023 - 2025
 * Author: Haizhao Dai
 * Email: daihzh2023@shanghaitech.edu.cn
 */

#include "camera.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

Camera* camera_create(Vector3f look_from, Vector3f look_to, Vector3f ref_up, Float y_fov, Float focal_length, Float aspect_ratio) {
    Camera* camera = (Camera*)malloc(sizeof(Camera));
    assert(camera != NULL);

    camera->look_from = look_from;
    camera->look_to = look_to;
    camera->ref_up = ref_up;

    camera->y_fov = y_fov;
    camera->focal_length = focal_length;
    camera->aspect_ratio = aspect_ratio;

    // Compute the camera coordinate system.
    camera->look_front = vector3_unit(vector3_sub(look_to, look_from));
    camera->look_right = vector3_unit(vector3_cross(camera->look_front, ref_up));
    camera->look_up = vector3_unit(vector3_cross(camera->look_right, camera->look_front));

    // Compute the camera frame.
    camera->vertical = vector3_scalar_mul(camera->look_up, tan(camera->y_fov * 0.5) * focal_length);
    camera->horizontal = vector3_scalar_mul(camera->look_right, camera->aspect_ratio * vector3_norm(camera->vertical));

    return camera;
}

void camera_destroy(Camera* camera) {
    free(camera);
}

void camera_set_film(Camera* camera, Film* film) {
    assert(camera != NULL);
    assert(film != NULL);

    camera->film = film;
}

Ray camera_get_ray(Camera const* camera, uint32_t x, uint32_t y) {
    assert(camera != NULL);
    assert(camera->film != NULL);

    // Instead of shooting ray to the corner of the pixel,
    // we shoot ray to the center of the pixel (x + 0.5, y + 0.5).
    Float u = (2.0 * ((Float)x + 0.5) / (Float)camera->film->width) - 1.0;
    Float v = (2.0 * ((Float)y + 0.5) / (Float)camera->film->height) - 1.0;

    Point3f origin = camera->look_from;
    Point3f direction = vector3_add(
        vector3_add(
            vector3_scalar_mul(camera->horizontal, u),
            vector3_scalar_mul(camera->vertical, -v)
        ),
        vector3_scalar_mul(camera->look_front, camera->focal_length)
    );

    return (Ray){ origin, direction };
}

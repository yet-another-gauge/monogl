/*
 * This file is part of the 'Yet another gauge' project.
 *
 * Copyright (C) 2018 Ivan Dyachenko <vandyachen@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef YET_ANOTHER_GAUGE__MONOGL__CANVAS_H
#define YET_ANOTHER_GAUGE__MONOGL__CANVAS_H

#include <stddef.h>

#include "monogl_types.h"

/**
 * @brief Allocate a struct monogl_canvas_t, intended to be used as a canvas
 * @param [in] width
 * @param [in] height
 * @param [in] pixels Pointer to pixels buffer (must outlast this canvas)
 * @return Created monogl_canvas_t
 */
MONOGL_API monogl_canvas_t *monogl_canvas_new(uint8_t width, uint8_t height, void *const pixels);

/**
 * @brief Free the memory for the given monogl_canvas_t
 * @param [in,out] canvas
 */
MONOGL_API void monogl_canvas_delete(monogl_canvas_t *);

/**
 * @brief Translate matrix by dx along the x-axis and dy along the y-axis
 * @param [in,out] canvas
 * @param [in] dx Distance to translate in x
 * @param [in] dy Distance to translate in y
 */
MONOGL_API void monogl_canvas_translate(monogl_canvas_t *const, uint8_t dx, uint8_t dy);

/**
 * @brief Clear given canvas
 * @param [in,out] canvas
 */
MONOGL_API void monogl_canvas_clear(monogl_canvas_t *const);

/**
 * @brief Draw point at (x, y)
 * @param [in,out] canvas
 * @param [in] x
 * @param [in] y
 */
MONOGL_API void monogl_canvas_draw_point(monogl_canvas_t *const, uint8_t x, uint8_t y);

#endif // YET_ANOTHER_GAUGE__MONOGL__CANVAS_H

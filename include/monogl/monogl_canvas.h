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

#include "monogl_types.h"

MONOGL_C_PLUS_PLUS_BEGIN_GUARD

/**
 * @brief Allocate a struct monogl_canvas_t, intended to be used as a canvas
 * @param [in] width
 * @param [in] height
 * @param [in] dots Pointer to dots buffer (must outlast this canvas)
 * @param [in] byte_size
 * @return Created monogl_canvas_t
 */
MONOGL_API monogl_canvas_t *monogl_canvas_new(uint16_t width, uint16_t height, void *const dots, size_t byte_size);

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
MONOGL_API void monogl_canvas_translate(const monogl_canvas_t *const, uint16_t dx, uint16_t dy);

/**
 * @brief Clear the given canvas
 * @param [in,out] canvas
 */
MONOGL_API void monogl_canvas_clear(const monogl_canvas_t *const);

/**
 * @brief Draw the specified dot
 * @param [in,out] canvas
 * @param [in] x
 * @param [in] y
 * @param [in] color
 */
MONOGL_API void monogl_canvas_draw_dot(const monogl_canvas_t *const, uint16_t x, uint16_t y, monogl_color_t color);

/**
 * @brief Draw the specified rectangle
 * @param [in,out] canvas
 * @param [in] x1
 * @param [in] y1
 * @param [in] x2
 * @param [in] y2
 */
MONOGL_API void monogl_canvas_draw_rect(const monogl_canvas_t *const,
                                        uint16_t x1,
                                        uint16_t y1,
                                        uint16_t x2,
                                        uint16_t y2);

/**
 * @brief Draw the specified image with it's top-left corner at (x,y)
 * @param [in,out] canvas
 * @param [in] x
 * @param [in] y
 * @param [in] image
 */
MONOGL_API void monogl_canvas_draw_image(const monogl_canvas_t *const,
                                         uint16_t x,
                                         uint16_t y,
                                         const monogl_image_t *const);

MONOGL_C_PLUS_PLUS_END_GUARD

#endif // YET_ANOTHER_GAUGE__MONOGL__CANVAS_H

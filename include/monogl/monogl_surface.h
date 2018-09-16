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

#ifndef YET_ANOTHER_GAUGE__MONOGL__SURFACE_H
#define YET_ANOTHER_GAUGE__MONOGL__SURFACE_H

#include "monogl_types.h"

/**
 * @brief Allocate a struct monogl_surface_t, intended to be used as a surface
 * @param [in] width Number of dots in each row
 * @param [in] height Number of dots in each column
 * @return Created monogl_surface_t
 */
MONOGL_API monogl_surface_t *monogl_surface_new(uint16_t width, uint16_t height);

/**
 * @brief Free the memory for the given surface
 * @param [in,out] surface
 */
MONOGL_API void monogl_surface_delete(monogl_surface_t *);

/**
 * @brief Return canvas that draws into surface
 * @param [in] surface
 * @return The canvas
 */
MONOGL_API const monogl_canvas_t *monogl_surface_get_canvas(const monogl_surface_t *const);

/**
 * @brief Return pointer to dots buffer
 * @param [in] surface
 * @return Pointer to dots buffer
 */
MONOGL_API void *monogl_surface_get_dots(const monogl_surface_t *const);

/**
 * @brief Return byte size of dots buffer
 * @param [in] surface
 * @return Byte size of dots buffer
 */
MONOGL_API size_t monogl_surface_get_byte_size(const monogl_surface_t *const);

#endif // YET_ANOTHER_GAUGE__MONOGL__SURFACE_H

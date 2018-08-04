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

#ifndef YET_ANOTHER_GAUGE__MONOGL__SURFACE_INFO_H
#define YET_ANOTHER_GAUGE__MONOGL__SURFACE_INFO_H

#include <stddef.h>

#include "monogl_types.h"

/**
 * @brief Allocate a struct monogl_surface_info_t, intended to be used as an information about surface
 * @param [in] width Number of pixels in each row
 * @param [in] height Number of pixels in each column
 * @return Created monogl_surface_info_t
 */
MONOGL_API monogl_surface_info_t *monogl_surface_info_new(uint8_t width, uint8_t height);

/**
 * @brief Free the memory for the given information about surface
 * @param [in,out] surface_info
 */
MONOGL_API void monogl_surface_info_delete(monogl_surface_info_t *);

/**
 * @brief Return number of pixels in each row
 * @param [in] surface_info
 * @return Number of pixels in each row
 */
MONOGL_API uint8_t monogl_surface_info_get_width(const monogl_surface_info_t *const);

/**
 * @brief Return number of pixels in each column
 * @param [in] surface_info
 * @return Number of pixels in each column
 */
MONOGL_API uint8_t monogl_surface_info_get_height(const monogl_surface_info_t *const);

/**
 * @brief Return total number of pixels
 * @param [in] surface_info
 * @return Total number of pixels
 */
MONOGL_API size_t monogl_surface_info_get_total_pixels(const monogl_surface_info_t *const);

#endif // YET_ANOTHER_GAUGE__MONOGL__SURFACE_INFO_H

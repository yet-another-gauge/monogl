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

#ifndef YET_ANOTHER_GAUGE__MONOGL__TYPES_H
#define YET_ANOTHER_GAUGE__MONOGL__TYPES_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#ifndef MONOGL_API
#define MONOGL_API
#endif

#ifdef __cplusplus
  #define MONOGL_C_PLUS_PLUS_BEGIN_GUARD  extern "C" {
  #define MONOGL_C_PLUS_PLUS_END_GUARD    }
#else
  #define MONOGL_C_PLUS_PLUS_BEGIN_GUARD
  #define MONOGL_C_PLUS_PLUS_END_GUARD
#endif

MONOGL_C_PLUS_PLUS_BEGIN_GUARD

typedef enum {
  /** white color */
      MONOGL_COLOR_WHITE = 0,
  /** black color */
      MONOGL_COLOR_BLACK = 1,
} monogl_color_t;

/**
 * @brief Describes a two dimensional array of dots to draw
 */
typedef struct monogl_image_t monogl_image_t;

/**
 * @brief Provides an interface for drawing
 */
typedef struct monogl_canvas_t monogl_canvas_t;

/**
 * @brief Responsible for managing the dots that a canvas draws into
 */
typedef struct monogl_surface_t monogl_surface_t;

MONOGL_C_PLUS_PLUS_END_GUARD

#endif // YET_ANOTHER_GAUGE__MONOGL__TYPES_H

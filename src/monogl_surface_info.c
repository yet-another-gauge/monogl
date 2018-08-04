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

#include <stdlib.h>
#include <stdint.h>

#include "monogl/monogl_surface_info.h"

struct monogl_surface_info_t {
  uint8_t width;
  uint8_t height;
  size_t total_pixels;
};

monogl_surface_info_t *monogl_surface_info_new(uint8_t width, uint8_t height) {
  monogl_surface_info_t *surface_info = malloc(sizeof(monogl_surface_info_t));

  surface_info->width = width;
  surface_info->height = height;
  surface_info->total_pixels = width * height;

  return surface_info;
}

void monogl_surface_info_delete(monogl_surface_info_t *surface_info) {
  if (surface_info != NULL) {
    free(surface_info);
  }
}

uint8_t monogl_surface_info_get_width(const monogl_surface_info_t *const surface_info) {
  return surface_info->width;
}

uint8_t monogl_surface_info_get_height(const monogl_surface_info_t *const surface_info) {
  return surface_info->height;
}

size_t monogl_surface_info_get_total_pixels(const monogl_surface_info_t *const surface_info) {
  return surface_info->total_pixels;
}

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

#include "monogl/monogl_canvas.h"
#include "monogl/monogl_surface.h"

struct monogl_surface_t {
  void *dots;
  size_t byte_size;

  monogl_canvas_t *canvas;
};

monogl_surface_t *monogl_surface_new(uint16_t width, uint16_t height) {
  monogl_surface_t *surface = malloc(sizeof(monogl_surface_t));

#if defined(GDDRAM)
  size_t byte_size = width * ((height + 7u) / 8u);
#else
  size_t byte_size = (width * height + 7u) / 8u;
#endif

  void *dots = malloc(byte_size);
  surface->dots = dots;
  surface->byte_size = byte_size;

  surface->canvas = monogl_canvas_new(width, height, dots, byte_size);

  return surface;
}

void monogl_surface_delete(monogl_surface_t *surface) {
  if (surface != NULL) {
    monogl_canvas_delete(surface->canvas);

    free(surface->dots);
    free(surface);
  }
}

const monogl_canvas_t *monogl_surface_get_canvas(const monogl_surface_t *const surface) {
  return surface->canvas;
}

void *monogl_surface_get_dots(const monogl_surface_t *const surface) {
  return surface->dots;
}

size_t monogl_surface_get_byte_size(const monogl_surface_t *const surface) {
  return surface->byte_size;
}

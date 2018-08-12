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

#include "monogl/monogl_canvas.h"

struct monogl_canvas_t {
  void *pixels;
  uint8_t width;
  uint8_t height;
};

monogl_canvas_t *monogl_canvas_new(uint8_t width, uint8_t height, void *const pixels) {
  monogl_canvas_t *canvas = malloc(sizeof(monogl_canvas_t));

  canvas->pixels = pixels;
  canvas->width = width;
  canvas->height = height;

  return canvas;
}

void monogl_canvas_delete(monogl_canvas_t *canvas) {
  if (canvas != NULL) {
    free(canvas);
  }
}

void monogl_canvas_clear(monogl_canvas_t *canvas) {
  uint8_t width = canvas->width;
  uint8_t height = canvas->height;
  uint8_t *base_ptr = (uint8_t *) canvas->pixels;

  size_t size = width * height / 8u;

  uint8_t *left_ptr = base_ptr;
  uint8_t *right_ptr = base_ptr + size;

  while (left_ptr < right_ptr) {
    *left_ptr = 0x00;
    left_ptr += 1;
  }
}

void monogl_canvas_draw_point(monogl_canvas_t *canvas, uint8_t x, uint8_t y) {
  uint8_t width = canvas->width;
  uint8_t *base_ptr = (uint8_t *) canvas->pixels;

  uint8_t *ptr = base_ptr + width * (7u - y / 8u) + x;
  *ptr |= (1u << (7u - y % 8u));
}

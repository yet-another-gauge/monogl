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

#include "monogl/monogl_image.h"
#include "monogl/monogl_canvas.h"

struct monogl_canvas_t {
  void *points;
  size_t byte_size;

  uint16_t width;
  uint16_t height;
};

monogl_canvas_t *monogl_canvas_new(uint16_t width, uint16_t height, void *const points, size_t byte_size) {
  monogl_canvas_t *canvas = malloc(sizeof(monogl_canvas_t));

  canvas->points = points;
  canvas->byte_size = byte_size;

  canvas->width = width;
  canvas->height = height;

  return canvas;
}

void monogl_canvas_delete(monogl_canvas_t *canvas) {
  if (canvas != NULL) {
    free(canvas);
  }
}

void monogl_canvas_clear(const monogl_canvas_t *const canvas) {
  uint8_t *base_ptr = (uint8_t *) canvas->points;
  size_t byte_size = canvas->byte_size;

  for (uint8_t *ptr = base_ptr; ptr < base_ptr + byte_size; ++ptr) {
    *ptr = 0x00u;
  }
}

void monogl_canvas_draw_point(const monogl_canvas_t *const canvas, uint16_t x, uint16_t y, monogl_color_t color) {
  uint16_t width = canvas->width;
  uint16_t height = canvas->height;

  if (x >= width || y >= height) {
    return;
  }

  uint8_t *base_ptr = (uint8_t *) canvas->points;

  uint32_t offset = y * width + x;

  uint8_t *ptr = base_ptr + offset / 8u;

  switch (color) {
    case MONOGL_COLOR_BLACK: {
      *ptr |= 0x80u >> (offset & 7u);
      break;
    }
    case MONOGL_COLOR_WHITE: {
      *ptr &= ~(0x80u >> (offset & 7u));
      break;
    }
  }
}

void monogl_canvas_draw_rect(const monogl_canvas_t *const canvas, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
  for (uint16_t i = x1; i <= x2; ++i) {
    for (uint16_t j = y1; j <= y2; ++j) {
      monogl_canvas_draw_point(canvas, i, j, MONOGL_COLOR_BLACK);
    }
  }
}

void monogl_canvas_draw_image(const monogl_canvas_t *const canvas,
                              uint16_t x,
                              uint16_t y,
                              const monogl_image_t *const image) {
  const uint8_t *image_base_ptr = monogl_image_get_points(image);

  uint16_t image_width = monogl_image_get_width(image);
  uint16_t image_height = monogl_image_get_height(image);

  for (uint16_t i = 0; i < image_width; ++i) {
    for (uint16_t j = 0; j < image_height; ++j) {
      uint32_t offset = j * image_width + i;

      monogl_color_t color = MONOGL_COLOR_WHITE;

      if (*(image_base_ptr + offset / 8u) & (0x80u >> (offset & 7u))) {
        color = MONOGL_COLOR_BLACK;
      }

      monogl_canvas_draw_point(canvas, x + i, y + j, color);
    }
  }
}

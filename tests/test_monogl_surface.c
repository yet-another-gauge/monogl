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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>

#include <unity.h>

#include "../include/monogl/monogl_canvas.h"
#include "../include/monogl/monogl_surface.h"

void test_monogl_surface_new(void) {
  uint16_t width = 132;
  uint16_t height = 64;

  monogl_surface_t *surface = monogl_surface_new(width, height);

  TEST_ASSERT_NOT_NULL(surface);

  monogl_surface_delete(surface);
}

void test_monogl_surface_delete(void) {
  // todo
}

void test_monogl_surface_get_canvas(void) {
  uint16_t width = 132;
  uint16_t height = 64;

  monogl_surface_t *surface = monogl_surface_new(width, height);
  monogl_canvas_t *canvas = monogl_surface_get_canvas(surface);

  TEST_ASSERT_NOT_NULL(canvas);

  monogl_surface_delete(surface);
}

void test_monogl_surface_get_dots(void) {
  uint16_t width = 3;
  uint16_t height = 11;

  monogl_surface_t *surface = monogl_surface_new(width, height);

  void *dots = monogl_surface_get_dots(surface);
  monogl_canvas_t *canvas = monogl_surface_get_canvas(surface);

  monogl_canvas_clear(canvas);

  monogl_canvas_draw_dot(canvas, 1, 0, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 0, 1, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 2, 1, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 0, 2, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 1, 2, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 2, 2, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 0, 4, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 1, 4, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 2, 4, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 0, 5, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 1, 6, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 2, 7, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 0, 8, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 1, 8, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 2, 8, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 0, 9, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 2, 9, MONOGL_COLOR_BLACK);
  monogl_canvas_draw_dot(canvas, 1, 10, MONOGL_COLOR_BLACK);

  size_t byte_size = (width * height + 7u) / 8u;
  uint8_t expected[5] = {0b01010111, 0b10001111, 0b00010001, 0b11110101, 0b00000000};

  TEST_ASSERT_NOT_NULL(dots);
  TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, dots, byte_size);

  monogl_surface_delete(surface);
}

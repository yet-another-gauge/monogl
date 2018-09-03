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
#include <stdint.h>

#include <unity.h>

#include "../include/monogl/monogl_image.h"
#include "../include/monogl/monogl_canvas.h"

void test_monogl_canvas_new(void) {
  uint16_t width = 132;
  uint16_t height = 64;

  size_t byte_size = (width * height + 7u) / 8u;
  uint8_t *dots = malloc(byte_size);

  monogl_canvas_t *canvas = monogl_canvas_new(width, height, dots, byte_size);

  TEST_ASSERT_NOT_NULL(canvas);
  TEST_ASSERT_NOT_NULL(dots);

  free(dots);
  monogl_canvas_delete(canvas);
}

void test_monogl_canvas_delete(void) {
  uint16_t width = 132;
  uint16_t height = 64;

  size_t byte_size = (width * height + 7u) / 8u;
  uint8_t *dots = malloc(byte_size);

  monogl_canvas_t *canvas = monogl_canvas_new(width, height, dots, byte_size);

  monogl_canvas_delete(canvas);

  TEST_ASSERT_NOT_NULL(dots);

  free(dots);
}

void test_monogl_canvas_clear(void) {
  uint16_t width = 132;
  uint16_t height = 64;

  size_t byte_size = (width * height + 7u) / 8u;
  uint8_t *dots = malloc(byte_size);

  monogl_canvas_t *canvas = monogl_canvas_new(width, height, dots, byte_size);

  monogl_canvas_clear(canvas);

  uint8_t expected[1056] = {[0 ... 1055] = 0x00u};

  TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, dots, byte_size);

  TEST_ASSERT_NOT_NULL(dots);

  free(dots);
  monogl_canvas_delete(canvas);
}

void test_monogl_canvas_draw_dot(void) {
  {
    uint16_t width = 3;
    uint16_t height = 5;

    uint8_t dots[2] = {0b00000000, 0b00000000};

    monogl_canvas_t *canvas = monogl_canvas_new(width, height, dots, 2);

    monogl_canvas_draw_dot(canvas, 0, 0, MONOGL_COLOR_BLACK);

    uint8_t expected[2] = {0b10000000, 0b00000000};

    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, dots, 2);

    monogl_canvas_delete(canvas);
  }

  {
    uint16_t width = 5;
    uint16_t height = 3;

    uint8_t dots[2] = {0b00000000, 0b00000000};

    monogl_canvas_t *canvas = monogl_canvas_new(width, height, dots, 2);

    monogl_canvas_draw_dot(canvas, 2, 1, MONOGL_COLOR_BLACK);

    uint8_t expected[2] = {0b00000001, 0b00000000};

    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, dots, 2);

    monogl_canvas_delete(canvas);
  }

  {
    uint16_t width = 5;
    uint16_t height = 3;

    uint8_t dots[2] = {0b00000000, 0b00000000};

    monogl_canvas_t *canvas = monogl_canvas_new(width, height, dots, 2);

    monogl_canvas_draw_dot(canvas, 4, 2, MONOGL_COLOR_BLACK);

    uint8_t expected[2] = {0b00000000, 0b00000010};

    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, dots, 2);

    monogl_canvas_delete(canvas);
  }

  {
    uint16_t width = 1;
    uint16_t height = 9;

    uint8_t dots[2] = {0b11111111, 0b11111111};

    monogl_canvas_t *canvas = monogl_canvas_new(width, height, dots, 2);

    monogl_canvas_draw_dot(canvas, 0, 0, MONOGL_COLOR_WHITE);
    monogl_canvas_draw_dot(canvas, 0, 2, MONOGL_COLOR_WHITE);
    monogl_canvas_draw_dot(canvas, 0, 4, MONOGL_COLOR_WHITE);
    monogl_canvas_draw_dot(canvas, 0, 6, MONOGL_COLOR_WHITE);
    monogl_canvas_draw_dot(canvas, 0, 8, MONOGL_COLOR_WHITE);

    uint8_t expected[2] = {0b01010101, 0b01111111};

    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, dots, 2);

    monogl_canvas_delete(canvas);
  }
}

void test_monogl_canvas_draw_rect(void) {
  // todo
}

void test_monogl_canvas_draw_image(void) {
  {
    uint8_t image_dots[2] = {0b10101010, 0b10101111};
    monogl_image_t *image = monogl_image_new(3, 4, image_dots);

    uint8_t canvas_dots[6] = {[0 ... 5] = 0b01010101};
    monogl_canvas_t *canvas = monogl_canvas_new(6, 8, canvas_dots, 6);

    monogl_canvas_draw_image(canvas, 2, 3, image);

    uint8_t expected[6] = {0b01010101, 0b01010101, 0b01011011, 0b01010101, 0b10110101, 0b01010101};

    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, canvas_dots, 6);

    monogl_image_delete(image);

    monogl_canvas_delete(canvas);
  }
}

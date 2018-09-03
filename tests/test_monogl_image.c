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

#include "../include/monogl/monogl_image.h"

void test_monogl_image_new(void) {
  uint16_t width = 132;
  uint16_t height = 64;

  size_t byte_size = (width * height + 7u) / 8u;
  uint8_t *dots = malloc(byte_size);

  monogl_image_t *image = monogl_image_new(width, height, dots);

  TEST_ASSERT_NOT_NULL(image);
  TEST_ASSERT_NOT_NULL(dots);

  free(dots);
  monogl_image_delete(image);
}

void test_monogl_image_delete(void) {
  uint16_t width = 132;
  uint16_t height = 64;

  size_t byte_size = (width * height + 7u) / 8u;
  uint8_t *dots = malloc(byte_size);

  monogl_image_t *image = monogl_image_new(width, height, dots);

  monogl_image_delete(image);

  TEST_ASSERT_NOT_NULL(dots);

  free(dots);
}

void test_monogl_image_get_width(void) {
  uint16_t width = 128;
  uint16_t height = 64;

  size_t byte_size = (width * height + 7u) / 8u;
  uint8_t *dots = malloc(byte_size);

  monogl_image_t *image = monogl_image_new(width, height, dots);

  TEST_ASSERT_EQUAL_UINT16(width, monogl_image_get_width(image));

  free(dots);
  monogl_image_delete(image);
}

void test_monogl_image_get_height(void) {
  uint16_t width = 128;
  uint16_t height = 64;

  size_t byte_size = (width * height + 7u) / 8u;
  uint8_t *dots = malloc(byte_size);

  monogl_image_t *image = monogl_image_new(width, height, dots);

  TEST_ASSERT_EQUAL_UINT16(height, monogl_image_get_height(image));

  free(dots);
  monogl_image_delete(image);
}

void test_monogl_image_get_dots(void) {
  uint16_t width = 128;
  uint16_t height = 64;

  size_t byte_size = (width * height + 7u) / 8u;
  uint8_t *dots = malloc(byte_size);

  monogl_image_t *image = monogl_image_new(width, height, dots);

  TEST_ASSERT_EQUAL_MEMORY(dots, monogl_image_get_dots(image), byte_size);

  free(dots);
  monogl_image_delete(image);
}

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

void test_monogl_image_create(void) {
  uint16_t width = 132;
  uint16_t height = 64;

  size_t byte_size = (width * height + 7u) / 8u;
  uint8_t *points = malloc(byte_size);

  monogl_image_t *image = monogl_image_new(width, height, points);

  TEST_ASSERT_EQUAL_UINT16(monogl_image_get_width(image), width);
  TEST_ASSERT_EQUAL_UINT16(monogl_image_get_height(image), height);

  monogl_image_delete(image);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_monogl_image_create);

  return UNITY_END();
}

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
#include <check.h>

#include "../include/monogl/monogl_image.h"

START_TEST(test_monogl_image_create) {
  uint16_t width = 132;
  uint16_t height = 64;
  uint8_t *points = malloc(width * height / 8u);

  monogl_image_t *image = monogl_image_new(width, 64, points);

  ck_assert_int_eq(monogl_image_get_width(image), width);
  ck_assert_int_eq(monogl_image_get_height(image), height);

  monogl_image_delete(image);
}
END_TEST

Suite *monogl_image_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("monogl image");

  // core test case
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_monogl_image_create);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = monogl_image_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
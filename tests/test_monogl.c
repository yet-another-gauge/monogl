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

#include <unity.h>

void test_monogl_image_new(void);
void test_monogl_image_delete(void);
void test_monogl_image_get_width(void);
void test_monogl_image_get_height(void);
void test_monogl_image_get_dots(void);

void test_monogl_canvas_new(void);
void test_monogl_canvas_delete(void);
void test_monogl_canvas_clear(void);
void test_monogl_canvas_draw_dot(void);
void test_monogl_canvas_draw_rect(void);
void test_monogl_canvas_draw_image(void);

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_monogl_image_new);
  RUN_TEST(test_monogl_image_delete);
  RUN_TEST(test_monogl_image_get_width);
  RUN_TEST(test_monogl_image_get_height);
  RUN_TEST(test_monogl_image_get_dots);

  RUN_TEST(test_monogl_canvas_new);
  RUN_TEST(test_monogl_canvas_delete);
  RUN_TEST(test_monogl_canvas_clear);
  RUN_TEST(test_monogl_canvas_draw_dot);
  RUN_TEST(test_monogl_canvas_draw_rect);
  RUN_TEST(test_monogl_canvas_draw_image);

  return UNITY_END();
}
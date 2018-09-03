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

struct monogl_image_t {
  void const *dots;

  uint16_t width;
  uint16_t height;
};

monogl_image_t *monogl_image_new(uint16_t width, uint16_t height, void const *const dots) {
  monogl_image_t *image = malloc(sizeof(monogl_image_t));

  image->dots = dots;
  image->width = width;
  image->height = height;

  return image;
}

void monogl_image_delete(monogl_image_t *image) {
  if (image != NULL) {
    free(image);
  }
}

uint16_t monogl_image_get_width(const monogl_image_t *const image) {
  return image->width;
}

uint16_t monogl_image_get_height(const monogl_image_t *const image) {
  return image->height;
}

void const *monogl_image_get_dots(const monogl_image_t *const image) {
  return image->dots;
}

# This file is part of the 'Yet another gauge' project.
#
# Copyright (C) 2018 Ivan Dyachenko <vandyachen@gmail.com>
#
# This library is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library. If not, see <http://www.gnu.org/licenses/>.

project(monogl C)

cmake_minimum_required(VERSION 3.0.2)

set(CMAKE_C_STANDARD 99)

option(BUILD_UNIT_TESTS "Build unit tests" OFF)
MESSAGE(STATUS "Build unit tests: ${BUILD_UNIT_TESTS}")

set(MONOGL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(MONOGL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(MONOGL_SOURCE_FILES
        ${MONOGL_SOURCE_DIR}/monogl_image.c
        ${MONOGL_SOURCE_DIR}/monogl_canvas.c
        ${MONOGL_SOURCE_DIR}/monogl_surface.c)

add_library(monogl OBJECT
        ${MONOGL_SOURCE_FILES})

target_include_directories(monogl PUBLIC
        ${MONOGL_INCLUDE_DIR})

if (BUILD_UNIT_TESTS)
    add_subdirectory(external)

    enable_testing()
    add_subdirectory(tests)
endif ()

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

set(UNITY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/unity)
set(UNITY_SOURCE_DIR ${UNITY_DIR}/src)

add_library(unity STATIC
        ${UNITY_SOURCE_DIR}/unity.c)

target_include_directories(unity PUBLIC
        ${UNITY_SOURCE_DIR})

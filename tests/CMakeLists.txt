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

include(CTest)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER cc)
set(CMAKE_C_FLAGS "-v ${CMAKE_C_FLAGS}")

set(TEST_SOURCES
        test_monogl_image.c)

add_executable(test_monogl
        ${TEST_SOURCES}
        $<TARGET_OBJECTS:monogl>)

target_link_libraries(test_monogl PRIVATE
        unity)

add_test(NAME test_monogl COMMAND test_monogl)

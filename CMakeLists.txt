cmake_minimum_required(VERSION 3.0.2)

set(MONOGL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(MONOGL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(MONOGL_SOURCE_FILES
        ${MONOGL_SOURCE_DIR}/monogl_image.c
        ${MONOGL_SOURCE_DIR}/monogl_canvas.c)

add_library(monogl OBJECT
        ${MONOGL_SOURCE_FILES})

target_include_directories(monogl PUBLIC
        ${MONOGL_INCLUDE_DIR})

add_subdirectory(external)

enable_testing()
add_subdirectory(tests)

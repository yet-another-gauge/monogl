cmake_minimum_required(VERSION 3.0.2)

add_library(monogl OBJECT
        ${CMAKE_CURRENT_SOURCE_DIR}/src/monogl_canvas.c)

target_include_directories(monogl PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/)

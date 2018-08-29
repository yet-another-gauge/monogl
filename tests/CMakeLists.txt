cmake_minimum_required(VERSION 3.0)

include(CTest)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER cc)
set(CMAKE_C_FLAGS "-v ${CMAKE_C_FLAGS}")

set(MONOGL_TEST_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(MONOGL_TEST_SOURCES
        # todo
        )

add_executable(check_monogl
        ${MONOGL_TEST_SOURCES}
        $<TARGET_OBJECTS:monogl>)

target_include_directories(check_monogl PRIVATE
        $<TARGET_PROPERTY:monogl,INTERFACE_INCLUDE_DIRECTORIES>)

target_link_libraries(check_monogl PRIVATE
        check compat)

add_test(check_monogl check_monogl)

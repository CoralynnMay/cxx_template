cmake_minimum_required(VERSION 3.28)

project(proj)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PROG main)

set(SOURCES
)

set(SOURCE_MAIN
    src/main.cpp
)

set(SOURCE_MAIN_TEST
    src/main_test.cpp
)

include_directories(lib/doctest)

add_executable(${PROG} ${SOURCE_MAIN} ${SOURCES})
target_compile_definitions(${PROG} PUBLIC DOCTEST_CONFIG_DISABLE)

add_executable(${PROG}_test ${SOURCES} ${SOURCE_MAIN_TEST})
add_custom_target(${PROG}_test_runner ALL DEPENDS ${PROG}_test COMMAND ${PROG}_test)

add_dependencies(${PROG} ${PROG}_test_runner)

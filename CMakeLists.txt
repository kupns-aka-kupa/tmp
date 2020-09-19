cmake_minimum_required(VERSION 3.5)

project(TMP LANGUAGES CXX)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(TESTS_DIR "${PROJECT_SOURCE_DIR}/test")
set(LABS_DIR "${PROJECT_SOURCE_DIR}/labs")

add_subdirectory(${SOURCE_DIR})
add_subdirectory(${LABS_DIR})
add_subdirectory(${TESTS_DIR})

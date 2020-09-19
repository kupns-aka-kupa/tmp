cmake_minimum_required(VERSION 3.5)

project(TMP LANGUAGES CXX)

set(MATH_TEST_DIR "${PROJECT_SOURCE_DIR}/MathTestCase")
set(LABS_TEST_DIR "${PROJECT_SOURCE_DIR}/LabsTestCase")

add_subdirectory(${MATH_TEST_DIR})
add_subdirectory(${LABS_TEST_DIR})

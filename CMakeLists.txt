cmake_minimum_required(VERSION 3.25)
project(UnitTestDemo)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(src bin)

include(CTest)
add_subdirectory(test)

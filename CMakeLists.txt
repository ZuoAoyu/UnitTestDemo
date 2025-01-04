cmake_minimum_required(VERSION 3.29)
project(UnitTestDemo)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src bin)

# 新添加
include(CTest)
add_subdirectory(test)

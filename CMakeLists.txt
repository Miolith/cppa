cmake_minimum_required(VERSION 3.14)
project(cppa_project CXX)

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)


add_compile_options(-W -Wall -Werror -std=c++20)


## MAIN library
add_library(cppa src/image.cpp src/firstVersion.cpp)
target_include_directories(cppa PUBLIC ${CMAKE_SOURCE_DIR}/include)


## TEST
add_subdirectory(tests)
add_subdirectory(benchs)

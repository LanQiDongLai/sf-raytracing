cmake_minimum_required(VERSION 3.20)

project(sf-raytracing)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCE src/*.cpp)

add_subdirectory(examples)
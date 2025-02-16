cmake_minimum_required(VERSION 3.20)

project(sf-raytracing)

file(GLOB_RECURSE SOURCE src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCE})

target_include_directories(${PROJECT_NAME} PRIVATE inc)
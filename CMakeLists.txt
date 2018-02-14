cmake_minimum_required(VERSION 3.9)

project(SDL2_Lessons)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_subdirectory(lesson_1)
add_subdirectory(lesson_2)
add_subdirectory(lesson_3)
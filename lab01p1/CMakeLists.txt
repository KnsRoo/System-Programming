cmake_minimum_required(VERSION 2.8.11)
project(SysProg_Lab_01_part_1 C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wpedantic -Wextra -Werror -std=c11")

add_subdirectory(SimpleFunctions)
add_subdirectory(Tests)
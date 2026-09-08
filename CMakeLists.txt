cmake_minimum_required(VERSION 4.2)
project(A03_starting_files C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(A03_starting_files
        data_structures.h
        declarations.h
        definitions.c
        main.c)

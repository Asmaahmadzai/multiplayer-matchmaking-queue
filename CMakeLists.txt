cmake_minimum_required(VERSION 4.2)
project(Multiplayer_Matchmaking_Queue C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Multiplayer_Matchmaking_Queue
        data_structures.h
        declarations.h
        definitions.c
        main.c)

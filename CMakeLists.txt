cmake_minimum_required(VERSION 3.24)
project(calendar_manager C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(calendar_manager
        fichier.c
        fichier.h
        main.c
        main.h part3.c part3.h)

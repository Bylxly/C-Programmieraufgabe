cmake_minimum_required(VERSION 4.0)
project(getraenkeautomat02 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(getraenkeautomat02
        ausgaben.c
        ausgaben.h
        getraenkeautomat02.c)

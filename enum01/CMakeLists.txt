cmake_minimum_required(VERSION 4.0)
project(enum01 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(enum01
        datentypen.h
        enum01.c)

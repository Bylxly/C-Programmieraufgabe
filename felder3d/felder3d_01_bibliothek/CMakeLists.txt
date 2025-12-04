cmake_minimum_required(VERSION 4.0)
project(felder3d_01_bibliothek C)

set(CMAKE_C_STANDARD 11)

add_library(felder3d_01_bibliothek STATIC felder3d_bibliothek.c)

target_include_directories(felder3d_01_bibliothek
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
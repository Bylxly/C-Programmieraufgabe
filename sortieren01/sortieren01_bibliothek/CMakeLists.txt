cmake_minimum_required(VERSION 4.0)
project(sortieren01_bibliothek C)

set(CMAKE_C_STANDARD 11)

add_library(sortieren01_bibliothek STATIC sortieren01_bibliothek.c)

target_include_directories(sortieren01_bibliothek
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
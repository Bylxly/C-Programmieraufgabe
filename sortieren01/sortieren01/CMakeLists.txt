cmake_minimum_required(VERSION 4.0)
project(sortieren01 C)

set(CMAKE_C_STANDARD 11)

add_executable(sortieren01
        sortieren01.c)

add_subdirectory(../sortieren01_bibliothek sortieren01_bibliothek_build)

target_link_libraries(sortieren01
        PRIVATE
        sortieren01_bibliothek
)
cmake_minimum_required(VERSION 4.0)
project(felder3d_01 C)

set(CMAKE_C_STANDARD 11)

add_executable(felder3d_01
        felder3d_01.c)

add_subdirectory(../felder3d_01_bibliothek felder3d_01_bibliothek_build)

target_link_libraries(felder3d_01
        PRIVATE
        felder3d_01_bibliothek
)
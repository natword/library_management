cmake_minimum_required(VERSION 3.29)
project(projet_bibliotheque)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)

add_executable(projet_bibliotheque
        src/main.c
        include/gestionlivre.h
        src/gestionlivre.c)

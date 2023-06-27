cmake_minimum_required(VERSION 3.25)
project(lista_encadeada C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lista_encadeada
        lista_encadeada.h
        main.c)

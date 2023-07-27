cmake_minimum_required(VERSION 3.25)
project(AED1)

set(CMAKE_CXX_STANDARD 14)

include_directories(atividade_06)
include_directories(atividade_06/lista_encadeada2)
include_directories(atividade_06/lista_encadeada3)

add_executable(AED1
        atividade_06/lista_encadeada2/lista_encadeada2.h
        atividade_06/lista_encadeada2/main2.c
        atividade_06/lista_encadeada3/lista_encadeada3.h
        atividade_06/lista_encadeada3/main3.c)

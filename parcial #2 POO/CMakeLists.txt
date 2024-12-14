cmake_minimum_required(VERSION 3.28)
project(parcial__2_POO)

set(CMAKE_CXX_STANDARD 20)

add_executable(parcial__2_POO main.cpp
        product.h
        product.cpp
        inventory.h
        inventory.cpp
        FileManager.h
        FileManager.cpp
        Sale.cpp
        Sale.h)

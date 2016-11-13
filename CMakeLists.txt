cmake_minimum_required(VERSION 3.6)
project(TrabajoPractico2)

file(GLOB Viajante "Viajante/*.cpp" "Viajante/*.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        ${Viajante}
        )

add_executable(TDA ${SOURCE_FILES})
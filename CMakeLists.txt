cmake_minimum_required(VERSION 3.6)
project(TrabajoPractico2)

file(GLOB Viajante "Viajante/*.cpp" "Viajante/*.h")
file(GLOB FlujoDeRedes "FlujoDeRedes/*.cpp" "FlujoDeRedes/*.h")
file(GLOB mochila "mochila/Source/*.cpp" "mochila/Headers/*.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        ${Viajante}
        ${FlujoDeRedes}
        ${mochila}
        )

add_executable(TDA ${SOURCE_FILES})
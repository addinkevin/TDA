cmake_minimum_required(VERSION 3.6)
project(TDA)

file(GLOB Ej2Headers "Ejercicio2/Headers/*.h")
file(GLOB Ej2Source "Ejercicio2/Source/*.cpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ${Ej2Headers} ${Ej2Source} )
add_executable(TDA ${SOURCE_FILES})
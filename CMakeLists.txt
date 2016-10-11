cmake_minimum_required(VERSION 3.6)
project(TDA)

file(GLOB Headers "Headers/*.h")
file(GLOB Sources "Source/*.cpp")
file(GLOB MapCreator "MapCreator/*.cpp" "MapCreator/*.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        ${Headers}
        ${Sources}
        ${MapCreator})

add_executable(TDA ${SOURCE_FILES})
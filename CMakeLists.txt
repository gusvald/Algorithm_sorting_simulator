cmake_minimum_required(VERSION 3.15)
project(algorytmy)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_STANDARD 14)

set("${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

include_directories(algorithm,pages)



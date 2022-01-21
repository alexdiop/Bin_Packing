cmake_minimum_required(VERSION 3.15)
project(BIN_PACKING)

set(CMAKE_CXX_STANDARD 14)

add_executable(BIN_PACKING GenerateBins.cpp Pack.cpp Pack.h)
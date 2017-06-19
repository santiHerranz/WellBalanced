cmake_minimum_required(VERSION 3.7)
project(WellBalanced)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cua_amb_2_piles.cpp cua_amb_2_piles.h)
add_executable(WellBalanced ${SOURCE_FILES})
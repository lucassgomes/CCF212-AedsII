cmake_minimum_required(VERSION 3.17)
project(SBB C)

set(CMAKE_C_STANDARD 99)

add_executable(SBB main.c Library/ADTSbb.c Library/ADTSbb.h)
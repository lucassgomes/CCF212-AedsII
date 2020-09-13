cmake_minimum_required(VERSION 3.17)
project(BSTv2 C)

set(CMAKE_C_STANDARD 99)

add_executable(BSTv2 main.c ADT/AdtBst.c ADT/AdtBst.h)
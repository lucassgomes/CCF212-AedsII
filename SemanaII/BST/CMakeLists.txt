cmake_minimum_required(VERSION 3.17)
project(BST C)

set(CMAKE_C_STANDARD 99)

add_executable(BST main.c library/ADTStudent.h library/ADTBst.c library/ADTBst.h library/ADTList.c library/ADTList.h)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scores.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
cmake_minimum_required(VERSION 3.29)
project(Lab6 C)

set(CMAKE_C_STANDARD 99)

add_executable(evens evens.c
        fe_test.c)
add_executable(odds odds.c
        fe_test.c)
add_executable(f_test f_test.c
        fe_test.c)

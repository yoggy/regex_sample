cmake_minimum_required(VERSION 2.8)

PROJECT(regex_sample)

set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_C_FLAGS "-g -Wall")

add_executable(regex_sample regex_sample.c)

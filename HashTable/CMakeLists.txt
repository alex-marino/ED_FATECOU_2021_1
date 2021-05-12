cmake_minimum_required(VERSION 3.19)
project(HashTable C)

set(CMAKE_C_STANDARD 99)

add_executable(HashTable main.c HashTable.c HashTable.h Util.c Util.h)
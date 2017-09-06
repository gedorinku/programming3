cmake_minimum_required(VERSION 3.8)
project(hayakuchi)

set(CMAKE_CXX_COMPILER gcc-7)
set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c mora.c mora.h morabigram.h morabigram.c word.c word.h dictionaryReader.c dictionaryReader.h dictionary.c dictionary.h)
add_executable(hayakuchi ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.28)
project("Practice_31_2" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practice_31_2 main.cpp
        include/toy.h
        include/shared_ptr_toy.h
        include/count_links.h)

target_include_directories(Practice_31_2 PUBLIC include)
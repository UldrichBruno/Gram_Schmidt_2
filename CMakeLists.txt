cmake_minimum_required(VERSION 3.15)
project(Gram_Schmidt)

set(CMAKE_CXX_STANDARD 14)

add_executable(Gram_Schmidt main.cpp vector.h vector.cpp matrix.cpp engine.cpp engine.h errors.h)
cmake_minimum_required(VERSION 3.17)
project(Calculoter)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calculator main.cpp token.cpp token.h analysis.cpp analysis.h)
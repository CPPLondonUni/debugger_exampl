
cmake_minimum_required(VERSION 3.1)

project(debug_demo CXX)

add_executable(debug_demo main.cpp)

target_compile_features(debug_demo PUBLIC cxx_std_14)



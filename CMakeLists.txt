cmake_minimum_required(VERSION 3.23)
project(chess)
add_executable(chess)
target_sources(chess 
    PRIVATE 
        src/chess.cpp
        src/main.cpp)

target_compile_features(chess PRIVATE cxx_std_20)
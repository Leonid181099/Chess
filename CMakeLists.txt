cmake_minimum_required(VERSION 3.23)
project(chess)
add_executable(chess)
target_sources(chess 
    PRIVATE 
        src/chess.cpp
        src/main.cpp)
cmake_minimum_required(VERSION 3.10)
project(chess_social)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")  # Add debug symbols

include_directories(/usr/local/include/cppcms)
link_directories(/usr/local/lib)

add_executable(chess_social main.cpp)
target_link_libraries(chess_social cppcms)
cmake_minimum_required(VERSION 3.28)
project(biltemacurl C)

set(CMAKE_C_STANDARD 23)

add_executable(biltemacurl main.c)
target_link_libraries(biltemacurl curl)
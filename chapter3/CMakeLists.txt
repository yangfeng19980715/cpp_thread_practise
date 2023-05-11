cmake_minimum_required(VERSION 3.5)

project(chapter3)

set(CMAKE_CXX_STANDARD 20)

set(SRC_FILE headers_ch3.h main_ch3.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(a.out ${SRC_FILE})

target_link_libraries(
  a.out
  pthread
)
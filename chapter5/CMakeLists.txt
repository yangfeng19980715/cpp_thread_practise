cmake_minimum_required(VERSION 3.5)

project(chapter5)

set(CMAKE_CXX_STANDARD 20)

set(SRC_FILE main.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
  ../headers/
)


add_executable(a.out ${SRC_FILE})

target_link_libraries(
  a.out
  pthread
)
cmake_minimum_required(VERSION 3.5)

project(chapte43)

set(CMAKE_CXX_STANDARD 20)

set(SRC_FILE headers_ch4.h main_ch4.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(a.out ${SRC_FILE})

target_link_libraries(
  a.out
  pthread
)
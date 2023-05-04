cmake_minimum_required(VERSION 3.5)

project(chapter3)

set(CMAKE_CXX_STANDARD 20)

set(SRC_FILE headers_ch3.h ../../headers/headers.h main_ch3.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(fmt CONFIG REQUIRED)

# find_package(Boost REQUIRED COMPONENTS boost asio)

add_executable(a.out ${SRC_FILE})

target_link_libraries(
  a.out
  PRIVATE
  fmt::fmt
  # Boost::boost
  # Boost::asio
)
cmake_minimum_required(VERSION 3.5.1)
project(mylib VERSION 0.0.1)

add_library(mylib mylib.cpp)
target_include_directories(mylib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)


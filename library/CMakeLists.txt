cmake_minimum_required(VERSION 3.5.1)
project(mylib)

# TODO How to build the tests using gtest from conan from here?

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

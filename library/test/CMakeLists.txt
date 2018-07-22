cmake_minimum_required(VERSION 3.5.1)
project(mylib-tests)

if (NOT TARGET mylib)
  find_package(mylib CONFIG REQUIRED)
endif()

enable_testing()
# TODO This fails on Ubuntu 16.04 with libgtest-dev package installed - why?
#find_package(GTest MODULE REQUIRED)
add_subdirectory(googletest)
# This alias is required so that we can link against GTest::Main if the googletest
# module was added with find_package() or with add_subdirectory().
add_library(GTest::Main ALIAS gtest_main)

add_executable(test_mylib test_mylib.cpp)
target_link_libraries(test_mylib PRIVATE
    myns::mylib GTest::Main
)
add_test(NAME test_mylib COMMAND test_mylib)

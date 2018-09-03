cmake_minimum_required(VERSION 3.5.1)
project(mylib-tests)

if (NOT TARGET mylib)
  find_package(mylib CONFIG REQUIRED)
endif()

enable_testing()

# Prefer getting gtest through conan if conan install was run previously
set (CONAN_BUILDINFO_FILE ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
if (EXISTS ${CONAN_BUILDINFO_FILE})
  message(STATUS "building gtest from conan")

  include(${CONAN_BUILDINFO_FILE})
  conan_basic_setup()
else()
  message(STATUS "building gtest from submodule")

  # TODO This fails on Ubuntu 16.04 with libgtest-dev package installed - why?
  #find_package(GTest MODULE REQUIRED)
  add_subdirectory(googletest)
  # This alias is required so that we can link against GTest::Main if the googletest
  # module was added with find_package() or with add_subdirectory().
  add_library(GTest::Main ALIAS gtest_main)
endif()

add_executable(test_mylib test_mylib.cpp)
target_link_libraries(test_mylib PRIVATE myns::mylib)

if (DEFINED CONAN_LIBS)
    target_link_libraries(test_mylib PRIVATE ${CONAN_LIBS})
else()
    target_link_libraries(test_mylib PRIVATE GTest::Main)
endif()

add_test(NAME test_mylib COMMAND test_mylib)

# CMake testing ground

## Talks and tutorials

* "Effective CMake" (C++Now 2017, Daniel Pfeifer): https://www.youtube.com/watch?v=bsXLMQ6WgIk
* "Git, CMake, Conan: How to Ship and Reuse our C++ Projects" (C++Now 2018, Mateusz Pusz): https://www.youtube.com/watch?v=6sWec7b0JIc

## Library

Demonstrates the basic directory layout and CMake files for a CMake based library (from the "Git, CMake, Conan: ..." talk).

There are 3 `CMakeLists.txt` files that can all be used as entry point for building parts of the library.

1) The `CMakeLists.txt` file in the `src` directory is used for building the library itself. It therefore contains the build instructions for the library as well as the install instructions which are largely boiler-plate.
2) The `CMakeLists.txt` file in the `test` directory is used for building the libraries tests. If this `CMakeListst.txt` is used directly, it will attempt to find the library using `find_package`. This will only work if the library itself was previously built and installed. This is useful as it can be used to check if the libraries install functionality works properly.
3) The top-level `CMakeLists.txt` file invokes the `src` and `test` `CMakeLists.txt` files. It is useful for development to build both the library and its tests simultaneously. Point your IDE to this `CMakeLists.txt` file. When using this `CMakeLists.txt` file, the `test` `CMakeLists.txt` file will not use `find_package` for finding the library as the target was already added by the `src` `CMakeLists.txt` file.

## TODO

* Add further explanation of what the library install instructions actually do in detail
* Use conan for installing 3rd party dependencies (e.g. gtest)
* Provide a conanfile for the library
cmake_minimum_required(VERSION 3.5.1)
project(mylib VERSION 0.0.1)

# Build library
add_library(mylib mylib.cpp)
target_include_directories(mylib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  )
add_library(myns::mylib ALIAS mylib)

# Install
install(TARGETS mylib EXPORT mylib-targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)
install(EXPORT mylib-targets
  DESTINATION lib/cmake/mylib
  FILE mylib-targets.cmake
  NAMESPACE myns::
)
install(DIRECTORY include/mylib
  DESTINATION include
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(mylib-config-version.cmake
  COMPATIBILITY SameMajorVersion
)
# Note that this file must be called mylibConfig.cmake or mylib-config.cmake
install(FILES mylib-config.cmake ${CMAKE_CURRENT_BINARY_DIR}/mylib-config-version.cmake
  DESTINATION lib/cmake/mylib
)

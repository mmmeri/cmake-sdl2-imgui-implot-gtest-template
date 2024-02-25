cmake_minimum_required(VERSION 3.15)
project(
  proj
  LANGUAGES CXX
  VERSION 1.0
)

set (CMAKE_CXX_STANDARD 17)

# For convenience of running the executables from the build directory
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(dependencies)
add_subdirectory(src)

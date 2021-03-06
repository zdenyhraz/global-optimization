cmake_minimum_required(VERSION 3.0)
project(global-optimization)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pthread -fvisibility=hidden")

get_directory_property(SUB_PROJECT PARENT_DIRECTORY)

if(NOT SUB_PROJECT)
  add_subdirectory(extern/fmt)
endif()

include_directories("include")
include_directories("extern/fmt/include")


# the library
add_library(globalopt INTERFACE)
add_library(globalopt::globalopt ALIAS globalopt)
target_include_directories(globalopt INTERFACE .)
target_link_libraries(globalopt INTERFACE fmt::fmt-header-only)


# the executable
add_executable(globalopt-test test/test.cpp)
target_link_libraries(globalopt-test PRIVATE fmt::fmt-header-only globalopt)



cmake_minimum_required(VERSION 3.0)
project(global-optimization)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pthread -fvisibility=hidden")

add_subdirectory(extern/fmt EXCLUDE_FROM_ALL)

include_directories("include")
include_directories("extern/fmt/include")

# the library
add_library(globalopt INTERFACE)
add_library(globalopt::globalopt ALIAS globalopt)
target_include_directories(globalopt INTERFACE .)

# the executable
add_executable(globalopt-exe main.cpp)
target_link_libraries(globalopt-exe PRIVATE fmt::fmt-header-only globalopt)



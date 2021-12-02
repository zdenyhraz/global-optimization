cmake_minimum_required(VERSION 3.0)
project(global-optimization)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pthread -fvisibility=hidden")

add_subdirectory(extern/fmt)

include_directories("include")
include_directories("extern/fmt/include")

# the library
add_library(global-optimization-lib INTERFACE)
target_include_directories(global-optimization-lib INTERFACE .)

# the executable
file(GLOB_RECURSE SRC_EXE CONFIGURE_DEPENDS main.cpp include/gopt/*.h include/gopt/*.cpp)
add_executable(global-optimization-exe ${SRC_EXE})
target_link_libraries(global-optimization-exe PRIVATE fmt::fmt-header-only)



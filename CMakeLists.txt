cmake_minimum_required(VERSION 3.0)
project(global-optimization)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pthread -fvisibility=hidden")

add_subdirectory(extern/fmt)

include_directories("include")
include_directories("extern/fmt/include")

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS main.cpp src/*.h src/*.cpp)

add_library(global-optimization ${SRC})

#add_executable(global-optimization-exe ${SRC})
#target_link_libraries(global-optimization-exe PRIVATE ${PYTHON_LIBRARIES} fmt::fmt-header-only)



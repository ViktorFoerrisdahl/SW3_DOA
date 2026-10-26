cmake_minimum_required(VERSION 3.10)
project(test_avl_check LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(test_avl_check src/test.cpp)
target_include_directories(test_avl_check PRIVATE include)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(test_avl_check PRIVATE -Wall -Wextra -Wpedantic)
endif()

cmake_minimum_required(VERSION 3.10)
project(test_min_heap_priority_queue LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(test_min_heap_priority_queue src/test.cpp)
target_include_directories(test_min_heap_priority_queue PRIVATE
    include
    ../Exercise02/include
)

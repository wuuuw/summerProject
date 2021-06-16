cmake_minimum_required(VERSION 3.19)
project(Project)
add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_17)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)

enable_testing()
add_subdirectory(C:/Users/ilins/CLionProjects/Project/doctest)
include(doctest/doctest.cmake)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML REQUIRED system window graphics network audio)
add_executable(Project main.cpp View.h Player.h)
add_executable(proj_test test.cpp View.h Player.h Map.h)
target_link_libraries(Project sfml-graphics sfml-audio sfml-window sfml-system default)
target_link_libraries(proj_test PUBLIC doctest::doctest default)

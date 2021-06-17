cmake_minimum_required(VERSION 3.19)
project(Project)
add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_17)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_subdirectory(doctest)
include(doctest/doctest.cmake)

set(SFML_STATIC_LIBRARIES TRUE)

set (SFML_DIR "C:/Users/ilins/CLionProjects/SFML/lib/cmake/SFML")

find_package(SFML REQUIRED system window graphics network audio)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/files
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(Project main.cpp)
add_executable(proj_test test.cpp)
target_link_libraries(Project sfml-graphics sfml-audio sfml-window sfml-system default)
target_link_libraries(proj_test PUBLIC doctest::doctest sfml-graphics sfml-audio sfml-window sfml-system default)

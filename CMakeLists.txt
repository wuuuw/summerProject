cmake_minimum_required(VERSION 3.19)
project(Project)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)

set(SFML_DIR "C:/Users/ilins/CLionProjects/Project/SFML/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML REQUIRED system window graphics network audio)
add_executable(Project main.cpp View.h)
target_link_libraries(Project sfml-graphics sfml-audio sfml-window sfml-system)
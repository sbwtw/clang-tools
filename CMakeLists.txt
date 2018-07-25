cmake_minimum_required(VERSION 3.7)

project(clang-tools)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
list(APPEND CMAKE_CXX_FLAGS "-Wall")

find_package(PkgConfig REQUIRED)
find_package(Clang REQUIRED Tooling)
find_package(LLVM REQUIRED)

add_subdirectory(include-sorter)

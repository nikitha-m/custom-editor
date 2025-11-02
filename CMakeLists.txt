cmake_minimum_required(VERSION 3.16)

# Project name and version
project(custom-editor
    VERSION 1.0.0
    DESCRIPTION "A custom text editor"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler-specific options (Google C++ Style Guide compliance)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(
        -Wall -Wextra -Wpedantic
        -Wconversion -Wsign-conversion
        -Wold-style-cast -Wcast-align
        -Wunused -Woverloaded-virtual
        -Wnon-virtual-dtor -Wshadow
    )
endif()

# Enable additional warnings for better code quality
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wmost -Wthread-safety)
endif()

# Include directories
include_directories(include)

# Add subdirectories
add_subdirectory(src)

# Optional: Enable testing
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

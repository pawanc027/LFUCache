cmake_minimum_required(VERSION 3.10)

# Project name and C++ standard
project(LFUCacheProject VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Define source and header directories
set(SRCDIR src)
set(OBJDIR obj)

# Collect all source files in the src directory
file(GLOB SRC_FILES "${SRCDIR}/*.cpp")

# Add an executable target
add_executable(LFUCache ${SRC_FILES})

# Set compile options
target_compile_options(LFUCache PRIVATE -Wall -Wextra -Werror -Wpedantic)


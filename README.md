# LFUCache

LFUCache is a C++20 program implementing a Least Frequently Used (LFU) cache. 
The program includes both the cache implementation and an example usage. The cache automatically removes the least frequently accessed items when it reaches its capacity.

## Features

- Implements LFU cache eviction policy.
- Configurable cache capacity.
- Efficient retrieval and updating of cache entries.

## Prerequisites

- C++20 compiler (e.g., g++ 10 or later)
- CMake 3.10 or later
- Make (optional, for building with Makefile)

## Directory Structure

LFUCache/
├── CMakeLists.txt
├── README.md
├── src/
│ └── main.cpp
└── build/ (generated after building)

## Building the Project

 mkdir build
 cd build
 cmake ../
 cmake --build .

## Running the Applications

 ./bin/LFUCache

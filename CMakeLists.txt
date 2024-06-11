# CMake
cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 26)

# Project properties
project(TrafficLightController)

# ScriptHookV
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/ScriptHookV/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/ScriptHookV/lib)

# Add source files
message(STATUS "Building TrafficLightController...")
include_directories(src lib)
file(GLOB_RECURSE SRC_MAIN
        src/*.cpp
        lib/*.cpp)

# Build
add_library(TrafficLightController SHARED "${SRC_MAIN}"
        src/tlc_pch.h)
target_link_libraries(TrafficLightController ScriptHookV)

# Force include common.hpp
target_precompile_headers(TrafficLightController PRIVATE src/tlc_pch.h)

# Set extension to .asi
set_target_properties(TrafficLightController PROPERTIES SUFFIX ".asi")
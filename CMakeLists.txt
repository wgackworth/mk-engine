# CMake Version
cmake_minimum_required(VERSION 3.5)

# Constants
set(PROJECT_NAME "mk")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Project Name
project(${PROJECT_NAME})

# Finding Library Binaries
find_library(GLEW_LIB NAMES GLEW HINTS "${CMAKE_SOURCE_DIR}/lib/linux")
find_library(GLFW_LIB NAMES glfw3 HINTS "${CMAKE_SOURCE_DIR}/lib/linux")

# Include Directories
include_directories("${CMAKE_SOURCE_DIR}/include")

# Library Binaries
link_libraries(m GL ${GLEW_LIB} ${GLFW_LIB})

# Subdirectories
add_subdirectory(examples)

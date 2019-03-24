cmake_minimum_required(VERSION 3.14)

project(flare LANGUAGES CUDA CXX)

# Set C++ standard.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set CUDA C++ standard.
set(CMAKE_CUDA_STANDARD 14)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_EXTENSIONS OFF)

# Check for CUDA version.
if (CMAKE_CUDA_COMPILER_ID STREQUAL "NVIDIA")
  if (CMAKE_CUDA_COMPILER_VERSION VERSION_LESS 10.0)
    message(FATAL_ERROR "${PROJECT_NAME} requires CUDA 10.0 or greater.")
  endif ()
else ()
  message(FATAL_ERROR "For CUDA, only the nvcc compiler is supported.")
endif ()

# Load CMake modules.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Add third party dependencies.
add_subdirectory(third_party)

# Add the project.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
enable_testing()
add_subdirectory(src)

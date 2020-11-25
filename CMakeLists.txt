cmake_minimum_required(VERSION 3.17...3.19 FATAL_ERROR)

project(flare LANGUAGES CUDA CXX)

# Set C++ standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set CUDA C++ standard.
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_EXTENSIONS OFF)

# Check for CUDA version.
if (CMAKE_CUDA_COMPILER_ID STREQUAL "NVIDIA")
  if (CMAKE_CUDA_COMPILER_VERSION VERSION_LESS 11.1)
    message(FATAL_ERROR "${PROJECT_NAME} requires CUDA 11.1 or greater.")
  endif ()
else ()
  message(FATAL_ERROR "For CUDA, only the nvcc compiler is supported.")
endif ()

# Use ccache if possible.
find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
  set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
  set(CMAKE_CUDA_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
endif ()

# Load CMake modules.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Add third party dependencies.
CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG release-1.10.0
  VERSION 1.10.0
  OPTIONS
    "INSTALL_GTEST OFF"
    "gtest_force_shared_crt"
)

# Add the project.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
enable_testing()
add_subdirectory(src)

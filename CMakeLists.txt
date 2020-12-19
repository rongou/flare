cmake_minimum_required(VERSION 3.19)

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
if(CMAKE_CUDA_COMPILER_ID STREQUAL "NVIDIA")
  if(CMAKE_CUDA_COMPILER_VERSION VERSION_LESS 11.2)
    message(FATAL_ERROR "${PROJECT_NAME} requires CUDA 11.2 or greater.")
  endif()
else()
  message(FATAL_ERROR "For CUDA, only the nvcc compiler is supported.")
endif()

# Use ccache if possible.
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
  set(CMAKE_CUDA_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
endif()

# Add third party dependencies.
include(cmake/CPM.cmake)

CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG release-1.10.0
  VERSION 1.10.0
  OPTIONS
  "INSTALL_GTEST OFF"
  "gtest_force_shared_crt"
)

CPMAddPackage(
  NAME gRPC
  GITHUB_REPOSITORY grpc/grpc
  VERSION 1.34.0
  OPTIONS
  "gRPC_BUILD_CSHARP_EXT OFF"
  "gRPC_BUILD_GRPC_CSHARP_PLUGIN OFF"
  "gRPC_BUILD_GRPC_NODE_PLUGIN OFF"
  "gRPC_BUILD_GRPC_OBJECTIVE_C_PLUGIN OFF"
  "gRPC_BUILD_GRPC_PHP_PLUGIN OFF"
  "gRPC_BUILD_GRPC_PYTHON_PLUGIN OFF"
  "gRPC_BUILD_GRPC_RUBY_PLUGIN OFF"
)

# Add the project.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
enable_testing()
add_subdirectory(src)

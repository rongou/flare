cmake_minimum_required(VERSION 3.14)

project(flare LANGUAGES CUDA CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if ("${CMAKE_CUDA_COMPILER_ID}" STREQUAL "NVIDIA")
  if (CMAKE_CUDA_COMPILER_VERSION VERSION_LESS 10.0)
    message(FATAL_ERROR "Insufficient nvcc version")
  endif ()
else ()
  message(WARNING "You are using an unsupported CUDA compiler! Compilation has only been tested with nvcc.")
endif ()
if (NOT DEFINED CMAKE_CUDA_STANDARD)
  set(CMAKE_CUDA_STANDARD 14)
  set(CMAKE_CUDA_STANDARD_REQUIRED ON)
endif ()

add_subdirectory(third_party)

add_executable(flare src/cli/flare.cpp)
target_link_libraries(flare readline)

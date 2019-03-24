set(srcs flare.cpp)

add_executable(flare ${srcs})
target_link_libraries(flare protos readline)

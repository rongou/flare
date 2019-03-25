set(srcs flare.cc)

add_executable(flare ${srcs})
target_link_libraries(flare protos readline)

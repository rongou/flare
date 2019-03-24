set(srcs sol.cc)

add_executable(sol ${srcs})
target_link_libraries(sol protos)

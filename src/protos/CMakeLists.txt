set(_PROTOBUF_LIBPROTOBUF libprotobuf)
set(_REFLECTION grpc++_reflection)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protoc>)
set(_GRPC_GRPCPP grpc++)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

set(_gRPC_PROTO_GENS_DIR ${CMAKE_CURRENT_BINARY_DIR}/proto-src)
file(MAKE_DIRECTORY ${_gRPC_PROTO_GENS_DIR})

get_filename_component(flare_proto "flare.proto" ABSOLUTE)
get_filename_component(flare_proto_path "${flare_proto}" PATH)

# Generated sources
set(flare_proto_srcs "${_gRPC_PROTO_GENS_DIR}/flare.pb.cc")
set(flare_proto_hdrs "${_gRPC_PROTO_GENS_DIR}/flare.pb.h")
set(flare_grpc_srcs "${_gRPC_PROTO_GENS_DIR}/flare.grpc.pb.cc")
set(flare_grpc_hdrs "${_gRPC_PROTO_GENS_DIR}/flare.grpc.pb.h")
add_custom_command(
  OUTPUT "${flare_proto_srcs}" "${flare_proto_hdrs}" "${flare_grpc_srcs}" "${flare_grpc_hdrs}"
  COMMAND ${_PROTOBUF_PROTOC}
  ARGS --grpc_out "${_gRPC_PROTO_GENS_DIR}"
    --cpp_out "${_gRPC_PROTO_GENS_DIR}"
    -I "${flare_proto_path}"
    --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
    "${flare_proto}"
  DEPENDS "${flare_proto}")

add_library(protos OBJECT ${flare_proto_srcs} ${flare_grpc_srcs})
target_include_directories(protos PUBLIC ${_gRPC_PROTO_GENS_DIR})
target_link_libraries(protos ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})

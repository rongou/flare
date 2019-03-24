find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)

set(srcs flare.proto)

set(PROTO_SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/proto-src)
file(MAKE_DIRECTORY ${PROTO_SRC_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC_DIR} ${srcs})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${srcs})

add_library(protos OBJECT ${PROTO_SRCS} ${GRPC_SRCS})
target_include_directories(protos PUBLIC ${PROTO_SRC_DIR})
target_link_libraries(protos gRPC::grpc++_reflection protobuf::libprotobuf)

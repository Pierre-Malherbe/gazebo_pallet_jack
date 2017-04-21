find_package(Protobuf REQUIRED)

set (msgs
  bool_msg.proto
)

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${msgs})

add_library(pallet_jack_msgs SHARED ${PROTO_SRCS})
target_link_libraries(pallet_jack_msgs ${PROTOBUF_LIBRARY})


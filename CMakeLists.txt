cmake_minimum_required(VERSION 3.5)
project(liyee)

# SET(CMAKE_BUILD_TYPE "Release")
# SET(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_module)
find_package(ProtoBuf REQUIRED)
include(cmake_module/utils.cmake)

file(GLOB ProtoFiles "${PROJECT_SOURCE_DIR}/proto/*.proto")
liyee_protobuf_generate_cpp(${CMAKE_CURRENT_SOURCE_DIR}/include/proto
  liyee_ProtoSrc
  liyee_ProtoHds
  ${ProtoFiles}
)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(liyee SHARED 
  src/log/log.cpp
  src/thread.cpp
  ${liyee_ProtoSrc}
  ${liyee_ProtoHds}
)
# target_include_directories(liyee PUBLIC
#   ${PROJECT_SOURCE_DIR}/include
# )

# add_executable(test_protobuf
#   test/test_protobuf.cpp
# )
# # target_include_directories(test_protobuf PUBLIC
# #   ${PROJECT_SOURCE_DIR}/include
# # )

# target_link_libraries(test_protobuf PUBLIC
#   liyee
#   ${PROTOBUF_LIBRARIES}
# )

set( LIBS
  liyee
  ${PROTOBUF_LIBRARIES}
)

liyee_add_test_executable(test_log "test/test_log.cpp" liyee "${LIBS}")
liyee_add_test_executable(test_protobuf "test/test_protobuf.cpp" liyee "${LIBS}")
liyee_add_test_executable(test_thread "test/test_thread.cpp" liyee "${LIBS}")
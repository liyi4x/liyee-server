cmake_minimum_required(VERSION 3.5)
project(liyee)

SET(CMAKE_BUILD_TYPE "Debug")

include_directories(${PROJECT_SOURCE_DIR}/include)


add_library(liyee SHARED 
    src/log/log.cpp
)

# add_library(liyee::library ALIAS liyee)

# target_include_directories(liyee
#     PUBLIC 
#         ${PROJECT_SOURCE_DIR}/include
# )



ADD_EXECUTABLE(test_log
    test/test_log.cpp
)

target_link_libraries(test_log PRIVATE
    # liyee::library
    liyee
)

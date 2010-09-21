CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(examples)

INCLUDE_DIRECTORIES(${libfacebookcpp_SOURCE_DIR})

LINK_DIRECTORIES(${libfacebookcpp_BINARY_DIR})

ADD_EXECUTABLE(examples main.cpp)

TARGET_LINK_LIBRARIES(examples libfacebookcpp)
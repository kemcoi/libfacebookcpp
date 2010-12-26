CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_LIBRARY(jsoncpp
	jsoncpp/src/lib_json/json_reader.cpp
	jsoncpp/src/lib_json/json_value.cpp
	jsoncpp/src/lib_json/json_writer.cpp
)

SET(JSONCPP_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/include/)
SET(JSONCPP_LIBRARIES jsoncpp)
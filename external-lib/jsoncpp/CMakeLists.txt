CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_LIBRARY(jsoncpp
	src/lib_json/json_reader.cpp
	src/lib_json/json_value.cpp
	src/lib_json/json_writer.cpp
	include/json/autolink.h
	include/json/config.h
	include/json/features.h
	include/json/forwards.h
	include/json/json.h
	include/json/reader.h
	include/json/value.h
	include/json/writer.h
)

INCLUDE_DIRECTORIES(include/)
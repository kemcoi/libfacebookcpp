CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(facebookcpp)

FIND_PACKAGE(curl)
IF(NOT CURL_FOUND)
	# If curl not found, build our own
	ADD_SUBDIRECTORY(external-lib/curl)
ENDIF(NOT CURL_FOUND)

# TODO: Make sure do a find for jsoncpp first as well
ADD_SUBDIRECTORY(external-lib/jsoncpp)

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(examples)
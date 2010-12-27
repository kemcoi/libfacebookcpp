CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(facebookcpp)

FIND_PACKAGE(curl)
IF(NOT CURL_FOUND)
	# If curl not found, build our own
	SET(CURL_VERSION "curl-7.21.3")

	SET(CURL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external-lib/${CURL_VERSION}/include/)
	SET(CURL_LIBRARIES libcurl)

	SET(BUILD_CURL_EXE OFF)
	SET(BUILD_CURL_TESTS OFF)

	ADD_SUBDIRECTORY(external-lib/${CURL_VERSION})
ENDIF(NOT CURL_FOUND)

# TODO: Make sure do a find for jsoncpp first as well
SET(JSONCPP_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external-lib/jsoncpp/include/)
SET(JSONCPP_LIBRARIES jsoncpp)
ADD_SUBDIRECTORY(external-lib/jsoncpp)

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(examples)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(examples)

################
## BEGIN HACK ##
################

SET(LIBFACEBOOKCPP_CURL_VERSION "curl-7.21.3")
SET(LIBFACEBOOKCPP_JSONCPP_VERSION "jsoncpp-src-0.5.0")

#FIND_PACKAGE(curl)
#IF(NOT CURL_FOUND)
	# If curl not found, build our own

#	SET(CURL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../src/external-lib/${LIBFACEBOOKCPP_CURL_VERSION}/include/)
#	SET(CURL_LIBRARIES libcurl)
#ENDIF(NOT CURL_FOUND)

# TODO: We don't have the support to link to jsoncpp right now. There is no standard find* for it and I don't have access
# to a *nix system to write a unified find* file. Hence, just force include it everytime
# IF(NOT JSONCPP_FOUND)
	#If jsoncpp is not found, build our own
	SET(JSONCPP_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../src/external-lib/${LIBFACEBOOKCPP_JSONCPP_VERSION}/include/)
	SET(JSONCPP_LIBRARIES jsoncpp)
# ENDIF(NOT JSONCPP_FOUND)

# TODO: I don't have the time to fix this CMake crap. It is really getting on my nerves now
# Hack it so it works now... I'll fix this later (or never)

INCLUDE_DIRECTORIES(../src/ ${CURL_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS})
ADD_EXECUTABLE(examples main.cpp)
TARGET_LINK_LIBRARIES(examples libfacebookcpp)

################
## END HACK ##
################
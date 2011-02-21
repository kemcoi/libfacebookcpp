CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(LIBFACEBOOKCPP_CURL_VERSION "curl-7.21.3")
SET(LIBFACEBOOKCPP_JSONCPP_VERSION "jsoncpp-src-0.5.0")

# FIND_PACKAGE(curl)
# IF(NOT CURL_FOUND)
# 	# If curl not found, build our own
# 
 	SET(CURL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external-lib/${LIBFACEBOOKCPP_CURL_VERSION}/include/)
 	SET(CURL_LIBRARIES libcurl)
# 
 	SET(BUILD_CURL_EXE OFF)
 	SET(BUILD_CURL_TESTS OFF)
# 
 	ADD_SUBDIRECTORY(external-lib/${LIBFACEBOOKCPP_CURL_VERSION})
# ENDIF(NOT CURL_FOUND)

# TODO: We don't have the support to link to jsoncpp right now. There is no standard find* for it and I don't have access
# to a *nix system to write a unified find* file. Hence, just force include it everytime
# IF(NOT JSONCPP_FOUND)
	#If jsoncpp is not found, build our own
	SET(JSONCPP_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external-lib/${LIBFACEBOOKCPP_JSONCPP_VERSION}/include/)
	SET(JSONCPP_LIBRARIES jsoncpp)

	ADD_SUBDIRECTORY(external-lib/${LIBFACEBOOKCPP_JSONCPP_VERSION})
# ENDIF(NOT JSONCPP_FOUND)

# REQUIRED since we don't carry a boost version
FIND_PACKAGE(BOOST 1.44.0 REQUIRED)

SET(LIBFACEBOOKCPP_SRCS
	Album.hpp
	AuthorizedObject.hpp
	Checkin.hpp
	Comment.hpp
	Common.hpp
	DateTime.hpp
	Deserializer.hpp
	Event.hpp
	Exception.hpp
	ExtendedPermissions.hpp
	Enum.hpp
	Friend.hpp
	From.hpp
	Group.hpp
	HttpRequest.hpp
	LibFacebookCpp.hpp
	Link.hpp
	List.hpp
	Location.hpp
	Logger.hpp
	Message.hpp
	Note.hpp
	PagingInfo.hpp
	Photo.hpp
	PolymorphicObject.hpp
	Post.hpp
	precompile.hpp
	ResponseBlob.hpp
	Serializer.hpp
	Session.hpp
	Status.hpp
	To.hpp
	User.hpp
	Utils.hpp
	Venue.hpp
	Version.hpp
	Video.hpp
	Album.cpp
	AuthorizedObject.cpp
	Checkin.cpp
	Comment.cpp
	DateTime.cpp
	Deserializer.cpp
	Event.cpp
	Exception.cpp
	ExtendedPermissions.cpp
	Friend.cpp
	From.cpp
	Group.cpp
	HTTPRequest.cpp
	LibFacebookCpp.cpp
	Link.cpp
	Location.cpp
	Logger.cpp
	Message.cpp
	Note.cpp
	Photo.cpp
	PolymorphicObject.cpp
	Post.cpp
	ResponseBlob.cpp
	Session.cpp
	Status.cpp
	To.cpp
	User.cpp
	Utils.cpp
	Venue.cpp
	Video.cpp
)

IF(WIN32)
	SET(LIBFACEBOOKCPP_SRCS
		${LIBFACEBOOKCPP_SRCS}
		libfacebookcpp.rc
	)
ENDIF(WIN32)

ADD_LIBRARY(libfacebookcpp
	${LIBFACEBOOKCPP_SRCS}
)

INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(libfacebookcpp ${CURL_LIBRARIES} ${JSONCPP_LIBRARIES} ${BOOST_LIBRARIES})

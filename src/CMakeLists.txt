CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(LIBFACEBOOKCPP_CURL_VERSION "curl-7.21.3")
SET(LIBFACEBOOKCPP_JSONCPP_VERSION "jsoncpp-src-0.5.0")

SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 2)
SET(VERSION_RELEASE 0)

# Since CURL and JsonCpp is hard to find on Windows, we package a version of these libraries in our source-tree

FIND_PACKAGE(CURL)
IF(NOT CURL_FOUND)
 	SET(CURL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external-lib/${LIBFACEBOOKCPP_CURL_VERSION}/include/)
 	SET(CURL_LIBRARIES libcurl)
 	SET(BUILD_CURL_EXE OFF)
 	SET(BUILD_CURL_TESTS OFF)
 	ADD_SUBDIRECTORY(external-lib/${LIBFACEBOOKCPP_CURL_VERSION})
ENDIF(NOT CURL_FOUND)

FIND_PACKAGE(JsonCpp 0.5.0)
IF(NOT JSONCPP_FOUND)
	SET(JSONCPP_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external-lib/${LIBFACEBOOKCPP_JSONCPP_VERSION}/include/)
	SET(JSONCPP_LIBRARIES jsoncpp)

	ADD_SUBDIRECTORY(external-lib/${LIBFACEBOOKCPP_JSONCPP_VERSION})
ENDIF(NOT JSONCPP_FOUND)

# REQUIRED since we don't carry a Boost version because Boost provides installer for Windows
FIND_PACKAGE(Boost 1.42.0 REQUIRED)

SET(LIBFACEBOOKCPP_HDRS
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
)

SET(LIBFACEBOOKCPP_SRCS
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

# TODO: Auto-generate this file!
IF(WIN32)
	SET(LIBFACEBOOKCPP_SRCS
		${LIBFACEBOOKCPP_SRCS}
		libfacebookcpp.rc
	)
ENDIF(WIN32)

ADD_LIBRARY(libfacebookcpp ${LIBFACEBOOKCPP_HDRS} ${LIBFACEBOOKCPP_SRCS})
INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(libfacebookcpp ${CURL_LIBRARIES} ${JSONCPP_LIBRARIES} ${Boost_LIBRARIES})

SET_TARGET_PROPERTIES(libfacebookcpp PROPERTIES SOVERSION ${VERSION_MAJOR} VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_RELEASE}")
INSTALL(FILES ${LIBFACEBOOKCPP_HDRS} DESTINATION /usr/local/include/libfacebookcpp)
INSTALL(TARGETS libfacebookcpp LIBRARY DESTINATION /usr/local/lib)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(LIBFACEBOOKCPP_CURL_VERSION "curl-7.21.3")
SET(LIBFACEBOOKCPP_JSONCPP_VERSION "jsoncpp-src-0.5.0")

SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 2)
SET(VERSION_RELEASE 0)

# Since CURL and JsonCpp is hard to find on Windows, we package a version of these libraries in our source-tree
# Quiet so we don't produce too much chatter
# TODO: Find the minimum sane CURL version
FIND_PACKAGE(CURL QUIET)
IF(NOT CURL_FOUND)
	MESSAGE(STATUS "Unable to find a pre-build version of CURL. Using the packaged version in the source-tree")
 	SET(CURL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external-lib/${LIBFACEBOOKCPP_CURL_VERSION}/include/)
 	SET(CURL_LIBRARIES libcurl)
 	SET(BUILD_CURL_EXE OFF)
 	SET(BUILD_CURL_TESTS OFF)
 	ADD_SUBDIRECTORY(external-lib/${LIBFACEBOOKCPP_CURL_VERSION})
ENDIF(NOT CURL_FOUND)

FIND_PACKAGE(JsonCpp 0.5.0 QUIET)
IF(NOT JSONCPP_FOUND)
	MESSAGE(STATUS "Unable to find a pre-build version of JsonCpp. Using the packaged version in the source-tree")
	SET(JSONCPP_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external-lib/${LIBFACEBOOKCPP_JSONCPP_VERSION}/include/)
	SET(JSONCPP_LIBRARIES jsoncpp)
	ADD_SUBDIRECTORY(external-lib/${LIBFACEBOOKCPP_JSONCPP_VERSION})
ENDIF(NOT JSONCPP_FOUND)

# REQUIRED since we don't carry a Boost version because it provides a good installer for Windows
FIND_PACKAGE(Boost 1.42.0 REQUIRED)

# XXX: Hack. This should be done better
SET(LIBFACEBOOKCPP_HDRS
	../include/LibFacebookCpp/Album.hpp
	../include/LibFacebookCpp/AuthorizedObject.hpp
	../include/LibFacebookCpp/Checkin.hpp
	../include/LibFacebookCpp/Comment.hpp
	../include/LibFacebookCpp/Common.hpp
	../include/LibFacebookCpp/DateTime.hpp
	../include/LibFacebookCpp/Deserializer.hpp
	../include/LibFacebookCpp/Event.hpp
	../include/LibFacebookCpp/Exception.hpp
	../include/LibFacebookCpp/ExtendedPermissions.hpp
	../include/LibFacebookCpp/Enum.hpp
	../include/LibFacebookCpp/Friend.hpp
	../include/LibFacebookCpp/From.hpp
	../include/LibFacebookCpp/Group.hpp
	../include/LibFacebookCpp/HttpRequest.hpp
	../include/LibFacebookCpp.hpp
	../include/LibFacebookCpp/Link.hpp
	../include/LibFacebookCpp/List.hpp
	../include/LibFacebookCpp/Location.hpp
	../include/LibFacebookCpp/Logger.hpp
	../include/LibFacebookCpp/Message.hpp
	../include/LibFacebookCpp/Note.hpp
	../include/LibFacebookCpp/PagingInfo.hpp
	../include/LibFacebookCpp/Photo.hpp
	../include/LibFacebookCpp/PolymorphicObject.hpp
	../include/LibFacebookCpp/Post.hpp
	../include/LibFacebookCpp/precompile.hpp
	../include/LibFacebookCpp/ResponseBlob.hpp
	../include/LibFacebookCpp/Serializer.hpp
	../include/LibFacebookCpp/Session.hpp
	../include/LibFacebookCpp/Status.hpp
	../include/LibFacebookCpp/To.hpp
	../include/LibFacebookCpp/User.hpp
	../include/LibFacebookCpp/Utils.hpp
	../include/LibFacebookCpp/Venue.hpp
	../include/LibFacebookCpp/Version.hpp
	../include/LibFacebookCpp/Video.hpp
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
	HttpRequest.cpp
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

# XXX: BAD BAD HACKS!
ADD_LIBRARY(libfacebookcpp ${LIBFACEBOOKCPP_HDRS} ${LIBFACEBOOKCPP_SRCS})
INCLUDE_DIRECTORIES(../include/ ../include/LibFacebookCpp/ ${CURL_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(libfacebookcpp ${CURL_LIBRARIES} ${JSONCPP_LIBRARIES} ${Boost_LIBRARIES})

SET_TARGET_PROPERTIES(libfacebookcpp PROPERTIES SOVERSION ${VERSION_MAJOR} VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_RELEASE}")
INSTALL(FILES ${LIBFACEBOOKCPP_HDRS} DESTINATION /usr/local/include/libfacebookcpp)
INSTALL(TARGETS libfacebookcpp
	RUNTIME DESTINATION /usr/local/bin
	LIBRARY DESTINATION /usr/local/lib
	ARCHIVE DESTINATION /usr/local/lib)
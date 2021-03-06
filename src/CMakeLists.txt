CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(LibFacebookCpp_CURL_VERSION "curl-7.21.3")
SET(LibFacebookCpp_JsonCpp_VERSION "jsoncpp-src-0.5.0")

SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 2)
SET(VERSION_RELEASE 0)

# Since CURL and JsonCpp is hard to find on Windows, we package a version of these libraries in our source-tree
# Quiet so we don't produce too much chatter
# TODO: Find the minimum sane CURL version

# XXX: Disabling all global find packages for now. Use internal libraries until I can get CMake to properly build everything nicely
# FIND_PACKAGE(CURL QUIET)
IF(NOT CURL_FOUND)
	MESSAGE(STATUS "Unable to find a pre-build version of CURL. Using the packaged version in the source-tree")
 	SET(CURL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external-lib/${LibFacebookCpp_CURL_VERSION}/include/)
 	SET(CURL_LIBRARIES libcurl)
 	SET(BUILD_CURL_EXE OFF)
 	SET(BUILD_CURL_TESTS OFF)
 	ADD_SUBDIRECTORY("external-lib/${LibFacebookCpp_CURL_VERSION}")
ENDIF()

# XXX: Disabling all global find packages for now. Use internal libraries until I can get CMake to properly build everything nicely
# FIND_PACKAGE(JsonCpp 0.5.0 QUIET)
IF(NOT JsonCpp_FOUND)
	MESSAGE(STATUS "Unable to find a pre-build version of JsonCpp. Using the packaged version in the source-tree")
	SET(JsonCpp_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/external-lib/${LibFacebookCpp_JsonCpp_VERSION}/include/)
	SET(JsonCpp_LIBRARIES jsoncpp)
	ADD_SUBDIRECTORY("external-lib/${LibFacebookCpp_JsonCpp_VERSION}")

ENDIF()

# REQUIRED since we don't carry a Boost version because it provides a good installer for Windows
FIND_PACKAGE(Boost 1.42.0 REQUIRED)

FILE(GLOB LibFacebookCpp_HDRS RELATIVE ../include/LibFacebookCpp/ "*.hpp")

MESSAGE(STATUS ${LibFacebookCpp_HDRS})

# XXX: Hack. This should be done better
SET(LibFacebookCpp_HDRS
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

SET(LibFacebookCpp_SRCS
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
	precompile.hpp
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
	SET(LibFacebookCpp_SRCS
		${LibFacebookCpp_SRCS}
		libfacebookcpp.rc
	)
ENDIF()

SET(LibFacebookCpp_DEPENDS ${CURL_LIBRARIES} ${JsonCpp_LIBRARIES} ${Boost_LIBRARIES})
SET(LibFacebookCpp_LIBRARIES LibFacebookCpp ${LibFacebookCpp_DEPENDS})

#TEMP:
# XXX: BAD BAD HACKS!
SET(LibFacebookCpp_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../include/ ${CURL_INCLUDE_DIRS} ${JsonCpp_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
SET(LibFacebookCpp_LIBRARIES LibFacebookCpp ${LibFacebookCpp_DEPENDS})

ADD_LIBRARY(LibFacebookCpp ${LibFacebookCpp_HDRS} ${LibFacebookCpp_SRCS})
ADD_DEFINITIONS(-DLIBFACEBOOKCPP_BUILDING)

# XXX: HACK HACK HACK
IF(BUILD_SHARED_LIBS)
	ADD_DEFINITIONS(-DLIBFACEBOOKCPP_BUILD_DYNAMIC)
ENDIF()

# XXX: HACK!
INCLUDE_DIRECTORIES(${LibFacebookCpp_INCLUDE_DIRS} ../include/LibFacebookCpp/)
TARGET_LINK_LIBRARIES(LibFacebookCpp ${LibFacebookCpp_DEPENDS})

EXPORT(TARGETS ${LibFacebookCpp_LIBRARIES} FILE "${PROJECT_BINARY_DIR}/LibFacebookCppDepends.cmake")
EXPORT(PACKAGE LibFacebookCpp)

CONFIGURE_FILE(LibFacebookCppConfig.cmake.in "${PROJECT_BINARY_DIR}/LibFacebookCppConfig.cmake" @ONLY)

#INSTALL(EXPORT LibFacebookCpp DESTINATION "${INSTALL_DATA_DIR}/LibFacebookCpp/CMake" COMPONENT dev)


 
## Create a FooBarConfig.cmake file for the use from the install tree
## and install it
#set(FOOBAR_INCLUDE_DIRS "${INSTALL_INCLUDE_DIR}")
#set(FOOBAR_LIB_DIR ${INSTALL_LIB_DIR}")
#set(FOOBAR_CMAKE_DIR "${INSTALL_DATA_DIR}/FooBar/CMake")
#configure_file(FooBarConfig.cmake.in
#  "${PROJECT_BINARY_DIR}/InstallFiles/FooBarConfig.cmake" @ONLY)
#install(FILES
#  "${PROJECT_BINARY_DIR}/InstallFiles/FooBarConfig.cmake"
#  DESTINATION "${FOOBAR_CMAKE_DIR} COMPONENT dev)





# Setup the install configuration parameters
#SET_TARGET_PROPERTIES(LibFacebookCpp PROPERTIES SOVERSION ${VERSION_MAJOR} VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_RELEASE}")
#INSTALL(FILES ${LibFacebookCpp_HDRS} DESTINATION /usr/local/include/libfacebookcpp)
#INSTALL(TARGETS libfacebookcpp
#	RUNTIME DESTINATION /usr/local/bin
#	LIBRARY DESTINATION /usr/local/lib
#	ARCHIVE DESTINATION /usr/local/lib)

# Temp:
#EXPORT(TARGETS ${LIBFACEBOOKCPP_LIBRARIES} FILE ${PROJECT_BINARY_DIR}/LIBFACEBOOKCPPDepends.cmake)
#EXPORT(PACKAGE libfacebookcpp)

# XXX: Project_binary_dir? WTF?! Magic CMake variables!
# XXX: Rename the uppercase libfacebookcpp to something sane
#CONFIGURE_FILE(LIBFACEBOOKCPP.cmake.in "${PROJECT_BINARY_DIR}/LIBFACEBOOKCPPConfig.cmake" @ONLY)

#INSTALL(EXPORT LIBFACEBOOKCPPDepends DESTINATION "${INSTALL_DATA_DIR}/LibFacebookCpp/CMake" COMPONENT dev)




#configure_file(FooBarConfig.cmake.in
#  "${PROJECT_BINARY_DIR}/FooBarConfig.cmake" @ONLY)
 
# Install the export set for use with the install-tree
#install(EXPORT FooBarLibraryDepends DESTINATION
  #"${INSTALL_DATA_DIR}/FooBar/CMake"
  #COMPONENT dev)
 
# Create a FooBarConfig.cmake file for the use from the install tree
# and install it
#set(FOOBAR_INCLUDE_DIRS "${INSTALL_INCLUDE_DIR}")
#set(FOOBAR_LIB_DIR ${INSTALL_LIB_DIR}")
#set(FOOBAR_CMAKE_DIR "${INSTALL_DATA_DIR}/FooBar/CMake")
#configure_file(FooBarConfig.cmake.in
#  "${PROJECT_BINARY_DIR}/InstallFiles/FooBarConfig.cmake" @ONLY)
#install(FILES
  #"${PROJECT_BINARY_DIR}/InstallFiles/FooBarConfig.cmake"
  #DESTINATION "${FOOBAR_CMAKE_DIR} COMPONENT dev)

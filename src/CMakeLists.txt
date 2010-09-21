CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(libfacebookcpp)

SET(LIBFACEBOOKCPP_SRCS
	Album.hpp
	AuthorizedObject.hpp
	Comment.hpp
	Common.hpp
	DateTime.hpp
	Deserializer.hpp
	Event.hpp
	Exception.hpp
	ExtendedPermissions.hpp
	Friend.hpp
	From.hpp
	Group.hpp
	HttpRequest.hpp
	LibFacebookCpp.hpp
	Link.hpp
	List.hpp
	Logger.hpp
	Message.hpp
	Note.hpp
	PagingInfo.hpp
	Photo.hpp
	PolymorphicObject.hpp
	Post.hpp
	precompile.hpp
	ResponseBlob.hpp
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
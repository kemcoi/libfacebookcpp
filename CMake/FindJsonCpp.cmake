# - Find JsonCpp
# Find the native JsonCpp headers and libraries. Currently tested to only work on an Ubuntu installation with a custom package

# Copyright (C) 2010-2011
# Written by:
# Aly Hirani <alyhirani@gmail.com>
# James Chou <uohcsemaj@gmail.com>
#
# All Rights Reserved
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.

# Look for the header file
FIND_PATH(JsonCpp_INCLUDE_DIR NAMES json/json.h)
MARK_AS_ADVANCED(JsonCpp_INCLUDE_DIR)

# Look for the library
FIND_LIBRARY(JsonCpp_LIBRARY NAMES
	libjsoncpp.so
)
MARK_AS_ADVANCED(JsonCpp_LIBRARY)

# Handle the QUIETLY and REQUIRED arguments and set JsonCpp_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(JsonCpp DEFAULT_MSG JsonCpp_LIBRARY JsonCpp_INCLUDE_DIR)

IF(JsonCpp_FOUND)
	SET(JsonCpp_LIBRARIES ${JsonCpp_LIBRARY})
	SET(JsonCpp_INCLUDE_DIRS ${JsonCpp_INCLUDE_DIR})
ENDIF(JsonCpp_FOUND)

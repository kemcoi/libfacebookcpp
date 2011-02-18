/*
 * Copyright (C) 2010-2011
 * Written by:
 * Aly Hirani <alyhirani@gmail.com>
 * James Chou <uohcsemaj@gmail.com>
 *
 * All Rights Reserved
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef LIBFACEBOOKCPP_H_
#define LIBFACEBOOKCPP_H_

#include "Common.hpp"
#include "List.hpp"

// TODO: Template instantiation

#include "ExtendedPermissions.hpp"
#include "Version.hpp"

// Aggregate includes here
#include "ResponseBlob.hpp"
#include "Album.hpp"
#include "Comment.hpp"
#include "From.hpp"
#include "Photo.hpp"
#include "Session.hpp"
#include "Status.hpp"
#include "User.hpp"
#include "Video.hpp"
#include "Note.hpp"
#include "Video.hpp"
#include "Venue.hpp"
#include "To.hpp"
#include "Message.hpp"
#include "Link.hpp"
#include "Friend.hpp"
#include "Group.hpp"
#include "Post.hpp"
#include "Event.hpp"
#include "PolymorphicObject.hpp"

namespace LibFacebookCpp
{

const char *GetMajorVersion();
const char *GetMinorVersion();
const char *GetRevisionVersion();

}

#endif // LIBFACEBOOKCPP_H_

/*
 * Copyright (C) 2010 
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

#include "Common.h"
#include "List.h"

namespace LibFacebookCpp
{

#define LIBFACEBOOKCPP_DEFINE_CLASS(x) \
	class LIBFACEBOOKCPP_API x; \
	template class LIBFACEBOOKCPP_API List<x>;

	LIBFACEBOOKCPP_DEFINE_CLASS(Photo);

#undef LIBFACEBOOKCPP_DEFINE_CLASS

}

#include "ExtendedPermissions.h"

// Aggregate includes here
#include "ResponseBlob.h"
#include "Album.h"
#include "Comment.h"
#include "From.h"
#include "Photo.h"
#include "Session.h"
#include "Status.h"
#include "User.h"
#include "Video.h"
#include "Note.h"
#include "Video.h"
#include "Venue.h"
#include "To.h"
#include "Message.h"
#include "Link.h"
#include "Friend.h"
#include "Group.h"
#include "Post.h"
#include "Event.h"
#include "PolymorphicObject.h"

#endif // LIBFACEBOOKCPP_H_

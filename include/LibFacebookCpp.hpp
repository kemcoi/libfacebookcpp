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

// TODO: Template instantiation
#include "LibFacebookCpp/Common.hpp"
#include "LibFacebookCpp/List.hpp"
#include "LibFacebookCpp/ExtendedPermissions.hpp"
#include "LibFacebookCpp/Version.hpp"
#include "LibFacebookCpp/ResponseBlob.hpp"
#include "LibFacebookCpp/Album.hpp"
#include "LibFacebookCpp/Comment.hpp"
#include "LibFacebookCpp/From.hpp"
#include "LibFacebookCpp/Photo.hpp"
#include "LibFacebookCpp/Session.hpp"
#include "LibFacebookCpp/Status.hpp"
#include "LibFacebookCpp/User.hpp"
#include "LibFacebookCpp/Video.hpp"
#include "LibFacebookCpp/Note.hpp"
#include "LibFacebookCpp/Video.hpp"
#include "LibFacebookCpp/Venue.hpp"
#include "LibFacebookCpp/To.hpp"
#include "LibFacebookCpp/Message.hpp"
#include "LibFacebookCpp/Link.hpp"
#include "LibFacebookCpp/Friend.hpp"
#include "LibFacebookCpp/Group.hpp"
#include "LibFacebookCpp/Post.hpp"
#include "LibFacebookCpp/Event.hpp"
#include "LibFacebookCpp/PolymorphicObject.hpp"

namespace LibFacebookCpp
{

const char *GetMajorVersion();
const char *GetMinorVersion();
const char *GetRevisionVersion();

}

#endif // LIBFACEBOOKCPP_H_

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

#include "precompile.h"
#include "ExtendedPermissions.h"

namespace Facebook
{

// ctor
ExtPermissions::ExtPermissions():requested_(false)
{
	URLString_.clear();
}

void ExtPermissions::requestPermission(FBExtPermissions permission)
{
FACEBOOK_ASSERT(permission >= FBEP_NO_PERMISSIONS && permission <= FBEP_FRIENDS_WORK_HISTORY);
if(permission == 0)
{
	// no permission requested
	URLString_.clear();
	requested_ = false;
	return;
}

// 1 here because no permissions requested is listed as a value
FACEBOOK_CASSERT((FACEBOOK_NUMELMS(permissionStrings)+1) == FBEP_NUMBER_OF_PERMISSIONS);

if(URLString_.size() != 0)
{
	URLString_ += ',';
}

URLString_ += permissionStrings[permission-1];
requested_ = true;
}

const std::string& ExtPermissions::getPermissionsString() const
{
	 GetInfoLog() << URLString_ << std::endl; 
	 return URLString_; 
}
}// Extended Permissions 

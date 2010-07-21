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
#include "Exception.h"

namespace LibFacebookCpp
{

void ExtendedPermissions::RequestPermission(ExtendedPermission permission)
{
	LIBFACEBOOKCPP_CHKARG(permission >= EP_PUBLISH_STREAM && permission < EP_COUNT)

	permissionFlags_.set(permission, true);
}

std::string ExtendedPermissions::GetPermissionsString() const
{
	static const char* s_permissionStrings[] = {
		"publish_stream",
		"create_event",
		"rsvp_event",
		"sms",
		"offline_access",
		"manage_pages",
		"email",
		"read_insights",
		"read_stream",
		"read_mailbox",
		"ads_management",
		"xmpp_login",
		"user_about_me",
		"user_activities",
		"user_birthday",
		"user_education_history",
		"user_events",
		"user_groups",
		"user_hometown",
		"user_interests",
		"user_likes",
		"user_location",
		"user_notes",
		"user_online_presence",
		"user_photo_video_tags",
		"user_photos",
		"user_relationships",
		"user_religion_politics",
		"user_status",
		"user_videos",
		"user_website",
		"user_work_history",
		"read_friendlists",
		"read_requests",
		"friends_about_me",
		"friends_activities",
		"friends_birthday",
		"friends_education_history",
		"friends_events",
		"friends_groups",
		"friends_hometown",
		"friends_interests",
		"friends_likes",
		"friends_location",
		"friends_notes",
		"friends_online_presence",
		"friends_photo_video_tags",
		"friends_photos",
		"friends_relationships",
		"friends_religion_politics",
		"friends_status",
		"friends_videos",
		"friends_website",
		"user_work_history"
	};

	LIBFACEBOOKCPP_CASSERT(LIBFACEBOOKCPP_NUMELMS(s_permissionStrings) == EP_COUNT);

	StringBuilder builder;
	bool firstPermission = true;
	for(int ii = 0; ii < EP_COUNT; ++ii)
	{
		if(permissionFlags_[ii])
		{
			if(firstPermission)
				firstPermission = false;
			else
				builder	<< ',';

			builder << s_permissionStrings[ii];
		}
	}
	return builder;
}

}// Extended Permissions 

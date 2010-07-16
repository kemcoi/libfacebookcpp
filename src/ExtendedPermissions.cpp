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

	
	static const char* permissionStrings[] = {
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
		"user_work_history"};


void ExtPermissions::requestPermission(FBExtPermissions permission)
{
	FACEBOOK_ASSERT(permission >= FBEP_PUBLISH_STREAM && permission <= FBEP_FRIENDS_WORK_HISTORY);
	FACEBOOK_CASSERT((FACEBOOK_NUMELMS(permissionStrings)) == FBEP_NUMBER_OF_PERMISSIONS);

	permissionFlags_[permission] = 1;
}

std::string ExtPermissions::getPermissionsString() const
{
	std::ostringstream oss;	
	bool firstPermission = false;
	for(int ii = 0; ii < __COUNT; ii++)
	{
		if(permissionFlags_[ii])
		{
			if(!firstPermission)
			{
				oss	<< ',';
			}
			oss << permissionStrings[ii];
		}
	}
	return oss.str();
}

}// Extended Permissions 

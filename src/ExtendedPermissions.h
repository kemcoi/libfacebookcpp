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


#ifndef FACEBOOK_EXTENDED_PERMISSIONS_H
#define FACEBOOK_EXTENDED_PERMISSIONS_H
#include "Common.h"
namespace Facebook
{
	

//-------------------------------------------------------------------

enum FACEBOOK_API FBExtPermissions{
	FBEP_NO_PERMISSIONS,
	FBEP_PUBLISH_STREAM, 
	FBEP_CREATE_EVENT, 
	FBEP_RSVP_EVENT,
	FBEP_SMS,
	FBEP_OFFLINE_ACCESS,
	FBEP_MANAGE_PAGES,
	FBEP_EMAIL,
	FBEP_READ_INSIGHTS, 
	FBEP_READ_STREAM, 
	FBEP_READ_MAILBOX, 
	FBEP_ADS_MANAGEMENT, 
	FBEP_XMPP_LOGIN, 
	FBEP_USER_ABOUT_ME,
	FBEP_USER_ACTIVITIES,
	FBEP_USER_BIRTHDAY,
	FBEP_USER_EDUCATION_HISTORY,
	FBEP_USER_EVENTS,
	FBEP_USER_GROUPS,
	FBEP_USER_HOMETOWN, 
	FBEP_USER_INTERESTS,
	FBEP_USER_LIKES,
	FBEP_USER_LOCATION, 
	FBEP_USER_NOTES, 
	FBEP_USER_ONLINE_PRESCENCE,
	FBEP_USER_PHOTO_VIDEO_TAGS, 
	FBEP_USER_PHOTOS, 
	FBEP_USER_RELATIONSHIPS,
	FBEP_USER_RELIGION_POLITICS,
	FBEP_FBEP_USER_STATUS,
	FBEP_USER_VIDEOS, 
	FBEP_USER_WEBSITE, 
	FBEP_USER_WORK_HISTORY,
	FBEP_READ_FRIENDLISTS, 
	FBEP_READ_REQUESTS, 
	FBEP_FRIENDS_ABOUT_ME, 
	FBEP_FRIENDS_ACTIVITIES, 
	FBEP_FRIENDS_BIRTHDAY, 
	FBEP_FRIENDS_EDUCATION_HISTORY,
	FBEP_FRIENDS_EVENTS,
	FBEP_FRIENDS_GROUPS, 
	FBEP_FRIENDS_HOMETOWN, 
	FBEP_FRIENDS_INTERESTS, 
	FBEP_FRIENDS_LIKES,
	FBEP_FRIENDS_LOCATION,  
	FBEP_FRIENDS_NOTES, 
	FBEP_FRIENDS_ONLINE_PRESCENCE, 
	FBEP_FRIENDS_PHOTO_VIDEO_TAGS,
	FBEP_FRIENDS_PHOTOS,
	FBEP_FRIENDS_RELATIONSHIPS, 
	FBEP_FRIENDS_RELIGION_POLITICS,
	FBEP_FBEP_FRIENDS_STATUS, 
	FBEP_FRIENDS_VIDEOS, 
	FBEP_FRIENDS_WEBSITE, 
	FBEP_FRIENDS_WORK_HISTORY,
	FBEP_NUMBER_OF_PERMISSIONS
};



struct FACEBOOK_API ExtPermissions
{

public:
	ExtPermissions();
	void requestPermission(FBExtPermissions permission);
	bool permissionsRequested()const { return requested_; } 
	const std::string& getPermissionsString() const;

private:
	std::string URLString_;
	bool requested_;
};


static const std::string permissionStrings[] = {
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

}

#endif
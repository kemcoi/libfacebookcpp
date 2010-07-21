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
#include <bitset>
namespace LibFacebookCpp
{
	

//-------------------------------------------------------------------

enum LIBFACEBOOKCPP_API ExtendedPermission{
	EP_PUBLISH_STREAM,
	EP_CREATE_EVENT,
	EP_RSVP_EVENT,
	EP_SMS,
	EP_OFFLINE_ACCESS,
	EP_MANAGE_PAGES,
	EP_EMAIL,
	EP_READ_INSIGHTS,
	EP_READ_STREAM,
	EP_READ_MAILBOX,
	EP_ADS_MANAGEMENT,
	EP_XMPP_LOGIN,
	EP_USER_ABOUT_ME,
	EP_USER_ACTIVITIES,
	EP_USER_BIRTHDAY,
	EP_USER_EDUCATION_HISTORY,
	EP_USER_EVENTS,
	EP_USER_GROUPS,
	EP_USER_HOMETOWN,
	EP_USER_INTERESTS,
	EP_USER_LIKES,
	EP_USER_LOCATION,
	EP_USER_NOTES,
	EP_USER_ONLINE_PRESCENCE,
	EP_USER_PHOTO_VIDEO_TAGS,
	EP_USER_PHOTOS,
	EP_USER_RELATIONSHIPS,
	EP_USER_RELIGION_POLITICS,
	EP_FBEP_USER_STATUS,
	EP_USER_VIDEOS,
	EP_USER_WEBSITE,
	EP_USER_WORK_HISTORY,
	EP_READ_FRIENDLISTS,
	EP_READ_REQUESTS,
	EP_FRIENDS_ABOUT_ME,
	EP_FRIENDS_ACTIVITIES,
	EP_FRIENDS_BIRTHDAY,
	EP_FRIENDS_EDUCATION_HISTORY,
	EP_FRIENDS_EVENTS,
	EP_FRIENDS_GROUPS,
	EP_FRIENDS_HOMETOWN,
	EP_FRIENDS_INTERESTS,
	EP_FRIENDS_LIKES,
	EP_FRIENDS_LOCATION,
	EP_FRIENDS_NOTES,
	EP_FRIENDS_ONLINE_PRESCENCE,
	EP_FRIENDS_PHOTO_VIDEO_TAGS,
	EP_FRIENDS_PHOTOS,
	EP_FRIENDS_RELATIONSHIPS,
	EP_FRIENDS_RELIGION_POLITICS,
	EP_FBEP_FRIENDS_STATUS,
	EP_FRIENDS_VIDEOS,
	EP_FRIENDS_WEBSITE,
	EP_FRIENDS_WORK_HISTORY,

	EP_COUNT
};

class LIBFACEBOOKCPP_API ExtendedPermissions
{

public:
	// ctor and ~()
	ExtendedPermissions(){};
	~ExtendedPermissions(){};

	void requestPermission(ExtendedPermission permission);
	bool permissionsRequested()const { return (0 != permissionFlags_.count()); } 
	std::string getPermissionsString() const;
	void clearRequestedPermissions() {permissionFlags_.reset(); }

private:
	std::bitset<EP_COUNT> permissionFlags_;
};

}

#endif

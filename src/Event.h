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

#include "AuthorizedObject.h"
#include "FriendContainer.h"
#include "Venue.h"
#include "DateTime.h"

namespace LibFacebookCpp
{

class PolymorphicObject;
class Venue;

class LIBFACEBOOKCPP_API Event : public AuthorizedObject
{
public: // accessors
	const std::string& GetId() const { return id_; }
	const FriendContainer& GetOwner() const { return owner_; }
	const std::string& GetName() const { return name_; }
	const std::string& GetDescription() const { return description_; }
	const DateTime& GetStartTime() const { return startTime_; }
	const DateTime& GetEndTime() const { return endTime_; }
	const std::string& GetLocation() const { return location_; }
	const Venue& GetVenue() const { return venue_; }
	const std::string& GetPrivacy() const { return privacy_; }
	const DateTime& GetUpdatedTime() const { return updatedTime_; }

public: // connections
	void GetFeedConnection(std::list<PolymorphicObject> *list, const PagingInfo *paging = NULL) const;
	void GetNoReplyConnection(std::list<FriendContainer> *list, const PagingInfo *paging = NULL) const;
	void GetMaybeConnection(std::list<FriendContainer> *list, const PagingInfo *paging = NULL) const;
	void GetInvitedConnection(std::list<FriendContainer> *list, const PagingInfo *paging = NULL) const;
	void GetAttendingConnection(std::list<FriendContainer> *list, const PagingInfo *paging = NULL) const;
	void GetDeclinedConnection(std::list<FriendContainer> *list, const PagingInfo *paging = NULL) const;
	void GetPictureConnection(FACEBOOK_PICTURE_SIZE size, ResponseBlob *blob);

protected: // callback functions
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string id_;
	FriendContainer owner_;
	std::string name_;
	std::string description_;
	DateTime startTime_;
	DateTime endTime_;
	std::string location_;
	Venue venue_;
	std::string privacy_;
	DateTime updatedTime_;
};

} // namespace LibFacebookCpp

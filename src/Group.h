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

#ifndef FACEBOOK_GROUP_H_
#define FACEBOOK_GROUP_H_

#include "AuthorizedObject.h"
#include "Friend.h"
#include "Venue.h"
#include "DateTime.h"

// XXX: Clean up the includes everywhere
// XXX: Clean up forward references everywhere

namespace LibFacebookCpp
{

class PolymorphicObject;
class Friend;

class LIBFACEBOOKCPP_API Group : public AuthorizedObject
{
public: // accessors
	const std::string& GetId() const { return id_; }
	const Friend& GetOwner() const { return owner_; }
	const std::string& GetName() const { return name_; }
	const std::string& GetDescription() const { return description_; }
	const std::string& GetLink() const { return link_; }
	const Venue& GetVenue() const { return venue_; }
	const std::string& GetPrivacy() const { return privacy_; }
	const DateTime& GetUpdatedTime() const { return updated_time_; }

public: // connections
	void GetFeed(std::list<PolymorphicObject> *list, const PagingInfo *paging = NULL) const;
	void GetMembers(std::list<Friend> *list, const PagingInfo *paging = NULL) const;
	// XXX: make sure all connections are const
	void GetPicture(FACEBOOK_PICTURE_SIZE size, ResponseBlob *blob) const;

protected:
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string id_;
	// XXX: Rename this
	Friend owner_;
	std::string name_;
	std::string description_;
	std::string link_;
	Venue venue_;
	// TODO: Enum?
	std::string privacy_;
	// XXX: Need a timestamp class
	DateTime updated_time_;
};

} // namespace LibFacebookCpp

#endif // FACEBOOK_GROUP_H_

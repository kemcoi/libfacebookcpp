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

// XXX: Make sure guards are in all the headers

// XXX: Rename FACEBOOK namespace to LIBFACEBOOKCPP?
#ifndef FACEBOOK_GROUP_H_
#define FACEBOOK_GROUP_H_

#include "AuthorizedObject.h"
#include "FriendContainer.h"
#include "Venue.h"
#include "DateTime.h"

// XXX: Clean up the includes everywhere
// XXX: Clean up forward references everywhere

namespace Facebook
{

class PolymorphicObject;
class FriendContainer;

class FACEBOOK_API Group : public AuthorizedObject
{
public: // accessors
	const std::string& Id() const { return id_; }
	const Facebook::FriendContainer& Owner() const { return owner_; }
	const std::string& Name() const { return name_; }
	const std::string& Description() const { return description_; }
	const std::string& Link() const { return link_; }
	const Venue& Venue() const { return venue_; }
	const std::string& Privacy() const { return privacy_; }
	const DateTime& UpdatedTime() const { return updated_time_; }

public: // connections
	void GetFeed(std::list<PolymorphicObject> *list, const PagingInfo *paging = NULL) const;
	void GetMembers(std::list<FriendContainer> *list, const PagingInfo *paging = NULL) const;
	// XXX: make sure all connections are const
	void GetPicture(FACEBOOK_PICTURE_SIZE size, ResponseBlob *blob) const;

protected:
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string id_;
	// XXX: Rename this
	Facebook::FriendContainer owner_;
	std::string name_;
	std::string description_;
	std::string link_;
	Facebook::Venue venue_;
	// TODO: Enum?
	std::string privacy_;
	// XXX: Need a timestamp class
	DateTime updated_time_;
};

} // namespace Facebook

#endif // FACEBOOK_GROUP_H_

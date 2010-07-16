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
#include "Group.h"
#include "Deserializer.h"
#include "PagingInfo.h"
#include "PolymorphicObject.h"

namespace Facebook
{

void Group::GetFeed(std::list<PolymorphicObject> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "feed", list, paging);
}

void Group::GetMembers(std::list<FriendContainer> *list, const PagingInfo *paging /*= NULL*/) const
{
	_GetConnection(id_, "members", list, paging);
}

void Group::GetPicture(FACEBOOK_PICTURE_SIZE size, ResponseBlob *blob) const
{
	_GetPictureConnection(id_, size, blob);
}

void Group::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer d(parent_obj, this, json);

	d.Deserialize("id", true, &id_);
	d.Deserialize("owner", false, &owner_);
	d.Deserialize("name", false, &name_);
	d.Deserialize("description", false, &description_);
	d.Deserialize("link", false, &link_);
	d.Deserialize("venue", false, &venue_);
	d.Deserialize("privacy", false, &privacy_);
	d.Deserialize("updated_time", false, &updated_time_);
}

} // namespace Facebook
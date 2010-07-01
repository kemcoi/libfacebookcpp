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

#include "User.h"
#include "Deserializer.h"
#include "HTTPRequest.h"
#include "PagingInfo.h"
#include "Photo.h"

namespace Facebook
{

void Location::Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer d(parent_obj, this, json);

	d.Deserialize("id", false, &id_);
	d.Deserialize("name", false, &name_);
}

void FriendContainer::Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer deserialize(parent_obj, this, json);

	deserialize.Deserialize("id", false, &id_);
	deserialize.Deserialize("name", false, &name_);
}

void User::Deserialize( const AuthorizedObject &parent_obj, const Json::Value &json )
{
	Deserializer deserialize(parent_obj, this, json);

	deserialize.Deserialize("id", true, &id_);
	deserialize.Deserialize("first_name", false, &first_name_);
	deserialize.Deserialize("last_name", false, &last_name_);
	deserialize.Deserialize("name", false, &name_);
	deserialize.Deserialize("link", false, &link_);
	deserialize.Deserialize("about", false, &about_);
	deserialize.Deserialize("birthday", false, &birthday_);
	deserialize.Deserialize("work", false, &work_);
	deserialize.Deserialize("email", false, &email_);
	deserialize.Deserialize("website", false, &website_);
	deserialize.Deserialize("hometown", false, &hometown_);
	deserialize.Deserialize("gender", false, &gender_);
	deserialize.Deserialize("interested_in", false, &interested_in_);
	deserialize.Deserialize("meeting_for", false, &meeting_for_);
	deserialize.Deserialize("relationship_status", false, &relationship_status_);
	deserialize.Deserialize("religion", false, &religion_);
	deserialize.Deserialize("political", false, &political_);
	deserialize.Deserialize("verified", false, &verified_);
	deserialize.Deserialize("significant_other", false, &significant_other_);
	deserialize.Deserialize("timezone", false, &timezone_);
}

void User::getFriendsList(std::list<FriendContainer>* friendList, const PagingInfo *paging /* = NULL */) const
{
	if(paging && !paging->IsValid())
		throw InvalidArgument("!paging->IsValid()");

	Facebook::Uri friendLink;
	GetHttpRequest()->GetUri(&friendLink);

	friendLink.base_uri = "https://graph.facebook.com/" + id_ + "/friends";

	if(paging)
		paging->GetUri(&friendLink);

	Json::Value userValues;
	GetHttpRequest()->GetResponse(friendLink, &userValues);

	Deserializer deserializer(*this, userValues);
	// Should always be able to get friend id and names
	deserializer.Deserialize("data", true, friendList);
}

void User::getPhotosList(std::list<Photo> *photoList, const PagingInfo *paging /* = NULL */) const
{
	FACEBOOK_ASSERT(photoList);

	Uri uri;
	GetHttpRequest()->GetUri(&uri);

	uri.base_uri = "https://graph.facebook.com/" + id_ + "/photos";

	if(paging)
		paging->GetUri(&uri);

	Json::Value value;
	GetHttpRequest()->GetResponse(uri, &value);

	Deserializer deserializer(*this, value);
	deserializer.Deserialize("data", true, photoList);
}

} // namespace Facebook

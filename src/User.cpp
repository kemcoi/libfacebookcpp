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
#include "HTTPRequest.h"
#include "Deserializer.h"
#include "PagingInfo.h"
#include "Photo.h"
#include "Album.h"
#include "Video.h"
#include "Status.h"
#include "Blob.h"

namespace Facebook
{

void Location::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer d(parent_obj, this, json);

	d.Deserialize("id", false, &id_);
	d.Deserialize("name", false, &name_);
}

void FriendContainer::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer deserialize(parent_obj, this, json);

	deserialize.Deserialize("id", false, &id_);
	deserialize.Deserialize("name", false, &name_);
}

void User::_Deserialize( const AuthorizedObject &parent_obj, const Json::Value &json )
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

void User::GetPicture(Blob *blob) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/picture", blob);
}

void User::getFriendsList(std::list<FriendContainer>* friendList, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/friends", friendList, paging);
}

void User::getPhotosList(std::list<Photo> *photoList, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/photos", photoList, paging);
}

void User::getAlbumsList(std::list<Album> *albumList, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/albums", albumList, paging);
}

void User::getVideosList(std::list<Video> *videoList, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/videos", videoList, paging);
}

void User::getStatusList(std::list<Status> *statusList, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/statuses", statusList, paging);
}

} // namespace Facebook

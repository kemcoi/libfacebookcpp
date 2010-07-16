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
#include "ResponseBlob.h"
#include "Post.h"
#include "From.h"
#include "Friend.h"
#include "Group.h"
#include "Link.h"
#include "Note.h"
#include "To.h"
#include "Message.h"
#include "Event.h"
#include "PolymorphicObject.h"

namespace LibFacebookCpp
{

void Location::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer d(parent_obj, this, json);

	d.Deserialize("id", false, &id_);
	d.Deserialize("name", false, &name_);
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

void User::GetHomeConnection(List<PolymorphicObject> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "home", list, paging);
}

void User::GetFeedConnection(List<PolymorphicObject> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "feed", list, paging);
}

void User::GetTaggedConnection(List<Photo> *list, const PagingInfo *paging /*= NULL*/) const
{
	_GetConnection(id_, "tagged", list, paging);
}

void User::GetPostsConnection(List<Post> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "posts", list, paging);
}

void User::GetPictureConnection(PictureSize size, ResponseBlob *blob) const
{
	_GetPictureConnection(id_, size, blob);
}

void User::GetFriendsConnection(List<Friend>* list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "friends", list, paging);
}

void User::GetActivitiesConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "activities", list, paging);
}

void User::GetInterestsConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "interests", list, paging);
}

void User::GetMusicConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "music", list, paging);
}

void User::GetBooksConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "books", list, paging);
}

void User::GetMoviesConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "movies", list, paging);
}

void User::GetTelevisionConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "television", list, paging);
}

void User::GetLikesConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "likes", list, paging);
}

void User::GetPhotosConnection(List<Photo> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "photos", list, paging);
}

void User::GetAlbumsConnection(List<Album> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "albums", list, paging);
}

void User::GetVideosConnection(List<Video> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "videos", list, paging);
}

void User::GetGroupsConnection(List<Group> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "groups", list, paging);
}

void User::GetStatusesConnection(List<Status> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "statuses", list, paging);
}

void User::GetLinksConnection(List<Link> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "links", list, paging);
}

void User::GetNoteConnection(List<Note> *list, const PagingInfo *paging) const
{
	_GetConnection(id_, "notes", list, paging);
}

void User::GetEventsConnection(List<Event> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "events", list, paging);
}

void User::GetInboxConnection(List<Message> *list, const PagingInfo *paging /*= NULL*/) const
{
	_GetConnection(id_, "inbox", list, paging);
}

void User::GetOutboxConnection(List<Message> *list, const PagingInfo *paging /*= NULL*/) const
{
	_GetConnection(id_, "outbox", list, paging);
}
} // namespace LibFacebookCpp

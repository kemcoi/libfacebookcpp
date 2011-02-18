/*
 * Copyright (C) 2010-2011
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

#include "precompile.hpp"

#include "User.hpp"
#include "HTTPRequest.hpp"
#include "Deserializer.hpp"
#include "PagingInfo.hpp"
#include "Photo.hpp"
#include "Album.hpp"
#include "Video.hpp"
#include "Status.hpp"
#include "ResponseBlob.hpp"
#include "Post.hpp"
#include "From.hpp"
#include "Friend.hpp"
#include "Group.hpp"
#include "Link.hpp"
#include "Note.hpp"
#include "To.hpp"
#include "Message.hpp"
#include "Event.hpp"
#include "PolymorphicObject.hpp"

namespace LibFacebookCpp
{

void Location::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer d(parent_obj, this, json);

	d.Deserialize("id", false, &id_);
	d.Deserialize("name", false, &name_);
}

void User::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
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
	_GetConnection(id_, "home", paging, list);
}

void User::GetFeedConnection(List<PolymorphicObject> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "feed", paging, list);
}

void User::GetTaggedConnection(List<Photo> *list, const PagingInfo *paging /*= NULL*/) const
{
	_GetConnection(id_, "tagged", paging, list);
}

void User::GetPostsConnection(List<Post> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "posts", paging, list);
}

void User::GetPictureConnection(PictureSize size, ResponseBlob *blob) const
{
	_GetPictureConnection(id_, size, blob);
}

void User::GetFriendsConnection(List<Friend>* list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "friends", paging, list);
}

void User::GetActivitiesConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "activities", paging, list);
}

void User::GetInterestsConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "interests", paging, list);
}

void User::GetMusicConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "music", paging, list);
}

void User::GetBooksConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "books", paging, list);
}

void User::GetMoviesConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "movies", paging, list);
}

void User::GetTelevisionConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "television", paging, list);
}

void User::GetLikesConnection(List<From> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "likes", paging, list);
}

void User::GetPhotosConnection(List<Photo> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "photos", paging, list);
}

void User::GetAlbumsConnection(List<Album> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "albums", paging, list);
}

void User::GetVideosConnection(List<Video> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "videos", paging, list);
}

void User::GetGroupsConnection(List<Group> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "groups", paging, list);
}

void User::GetStatusesConnection(List<Status> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "statuses", paging, list);
}

void User::GetLinksConnection(List<Link> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "links", paging, list);
}

void User::GetNoteConnection(List<Note> *list, const PagingInfo *paging) const
{
	_GetConnection(id_, "notes", paging, list);
}

void User::GetEventsConnection(List<Event> *list, const PagingInfo *paging /* = NULL */) const
{
	_GetConnection(id_, "events", paging, list);
}

void User::GetInboxConnection(List<Message> *list, const PagingInfo *paging /*= NULL*/) const
{
	_GetConnection(id_, "inbox", paging, list);
}

void User::GetOutboxConnection(List<Message> *list, const PagingInfo *paging /*= NULL*/) const
{
	_GetConnection(id_, "outbox", paging, list);
}
} // namespace LibFacebookCpp

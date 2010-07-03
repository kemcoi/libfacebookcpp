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
#include "Post.h"
#include "From.h"
#include "Note.h"

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

void User::GetTagged(std::list<Photo> *list, const PagingInfo *paging /*= NULL*/) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/tagged", list, paging);
}

void User::GetPosts(std::list<Post> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/posts", list, paging);
}

void User::GetPicture(Blob *blob) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/picture", blob);
}

void User::GetFriends(std::list<FriendContainer>* list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/friends", list, paging);
}

void User::GetActivities(std::list<From> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/activities", list, paging);
}

void User::GetInterests(std::list<From> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/interests", list, paging);
}

void User::GetMusic(std::list<From> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/music", list, paging);
}

void User::GetBooks(std::list<From> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/books", list, paging);
}

void User::GetMovies(std::list<From> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/movies", list, paging);
}

void User::GetTelevision(std::list<From> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/television", list, paging);
}

void User::GetLikes(std::list<From> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/likes", list, paging);
}

void User::GetPhotos(std::list<Photo> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/photos", list, paging);
}

void User::GetAlbums(std::list<Album> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/albums", list, paging);
}

void User::GetVideos(std::list<Video> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/videos", list, paging);
}

void User::GetStatuses(std::list<Status> *list, const PagingInfo *paging /* = NULL */) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/statuses", list, paging);
}

void User::GetNote(std::list<Note> *list, const PagingInfo *paging) const
{
	GetConnection("https://graph.facebook.com/" + id_ + "/notes", list, paging);
}
} // namespace Facebook

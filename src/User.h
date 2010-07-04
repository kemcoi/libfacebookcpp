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

#ifndef FACEBOOK_USER_H_
#define FACEBOOK_USER_H_

#include "AuthorizedObject.h"

namespace Facebook
{

class Group;
class FriendContainer;
class Post;
class From;
class Blob;
class Event;
class Video;
class Album;
class Link;
class Photo;
class Status;
struct PagingInfo;
class Note;
class Message;
class PolymorphicObject;

class FACEBOOK_API Location : public AuthorizedObject
{
public: // public interface
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) FACEBOOK_OVERRIDE;

public: // accessors
	const std::string& Id() const   { return id_; }
	const std::string& Name() const { return name_; }

private: // member variables
	std::string id_;
	std::string name_;
};

class FACEBOOK_API User: public AuthorizedObject
{
	typedef AuthorizedObject inherited;
public:
	//----------------------------------------------
	User() { }
	virtual ~User() { }
	//----------------------------------------------

	//----------------------------------------------
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) FACEBOOK_OVERRIDE;

	//----------------------------------------------
	//Getters
	const std::string& Id() const { return id_; }
	const std::string& FirstName() const { return first_name_; }
	const std::string& LastName() const { return last_name_; }
	const std::string& Name() const { return name_; }
	const std::string& Link() const { return link_; }
	const std::string& About() const { return about_; }
	const std::string& Birthday() const { return birthday_; }
	const std::string& Work() const { return work_; }
	const std::string& Education() const { return education_; }
	const std::string& Email() const { return email_; }
	const std::string& Website() const { return website_; }
	const Location& Hometown() const { return hometown_; }
	const Location& Location() const { return location_; }
	const std::string& Gender() const { return gender_; }
	const std::list<std::string>& InterestedIn() const { return interested_in_; }
	const std::string& MeetingFor() const { return meeting_for_; }
	const std::string& RelationshipStatus() const { return relationship_status_; }
	const std::string& Religion() const { return religion_; }
	const std::string& Political() const { return political_; }
	const std::string& Verified() const { return verified_; }
	const std::string& SignificantOther() const { return significant_other_; }
	// XXX: Timezone should probably be in decimal as opposed to int
	int Timezone() const { return timezone_; }

	//----------------------------------------------
	// Connections
	void GetHome(std::list<PolymorphicObject> *list, const PagingInfo *paging = NULL) const;
	void GetFeed(std::list<PolymorphicObject> *list, const PagingInfo *paging = NULL) const;
	void GetTagged(std::list<Photo> *list, const PagingInfo *paging = NULL) const;
	void GetPosts(std::list<Post> *list, const PagingInfo *paging = NULL) const;
	void GetPicture(Blob *blob) const;
	void GetFriends(std::list<FriendContainer>* list, const PagingInfo *paging = NULL) const;
	void GetActivities(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetInterests(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetMusic(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetBooks(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetMovies(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetTelevision(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetLikes(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetPhotos(std::list<Photo> *list, const PagingInfo *paging = NULL) const;
	void GetAlbums(std::list<Album> *list, const PagingInfo *paging = NULL) const;
	void GetVideos(std::list<Video> *list, const PagingInfo *paging = NULL) const;
	void GetGroups(std::list<Group> *list, const PagingInfo *paging = NULL) const;
	void GetStatuses(std::list<Status> *list, const PagingInfo *paging = NULL) const;
	void GetLinks(std::list<Facebook::Link> *list, const PagingInfo *paging = NULL) const;
	void GetNote(std::list<Note> *list, const PagingInfo *paging = NULL) const;
	void GetEvents(std::list<Event> *list, const PagingInfo *paging = NULL) const;
	void GetInbox(std::list<Message> *list, const PagingInfo *paging = NULL) const;
	void GetOutbox(std::list<Message> *list, const PagingInfo *paging = NULL) const;
	void GetUpdates(std::list<Message> *list, const PagingInfo *paging = NULL) const;
	// TODO: /accounts

protected:
private:
	std::string id_;
	std::string first_name_;
	std::string last_name_;
	std::string name_; //full name
	std::string link_;
	std::string about_;
	std::string birthday_;
	std::string work_;
	std::string education_;
	std::string email_;
	std::string website_;
	Facebook::Location hometown_;
	Facebook::Location location_;
	std::string gender_;
	std::list<std::string> interested_in_;
	std::string meeting_for_;
	std::string relationship_status_;
	std::string religion_;
	std::string political_;
	std::string verified_;
	std::string significant_other_;
	int timezone_;
};

} // namespace Facebook

#endif

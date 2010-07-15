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

#ifndef LIBFACEBOOKCPP_USER_H_
#define LIBFACEBOOKCPP_USER_H_

#include "AuthorizedObject.h"

namespace LibFacebookCpp
{

class Group;
class Friend;
class Post;
class From;
class ResponseBlob;
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

class LIBFACEBOOKCPP_API Location : public AuthorizedObject
{
public: // public interface
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) LIBFACEBOOKCPP_OVERRIDE;

public: // accessors
	const std::string& Id() const   { return id_; }
	const std::string& Name() const { return name_; }

private: // member variables
	std::string id_;
	std::string name_;
};

class LIBFACEBOOKCPP_API User: public AuthorizedObject
{
	typedef AuthorizedObject inherited;
public:
	//----------------------------------------------
	User() { }
	virtual ~User() { }
	//----------------------------------------------

	//----------------------------------------------
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) LIBFACEBOOKCPP_OVERRIDE;

	//----------------------------------------------
	//Getters
	const std::string& GetId() const { return id_; }
	const std::string& GetFirstName() const { return first_name_; }
	const std::string& GetLastName() const { return last_name_; }
	const std::string& GetName() const { return name_; }
	const std::string& GetLink() const { return link_; }
	const std::string& GetAbout() const { return about_; }
	const std::string& GetBirthday() const { return birthday_; }
	const std::string& GetWork() const { return work_; }
	const std::string& GetEducation() const { return education_; }
	const std::string& GetEmail() const { return email_; }
	const std::string& GetWebsite() const { return website_; }
	const Location& GetHometown() const { return hometown_; }
	const Location& GetLocation() const { return location_; }
	const std::string& GetGender() const { return gender_; }
	const std::list<std::string>& GetInterestedIn() const { return interested_in_; }
	const std::string& GetMeetingFor() const { return meeting_for_; }
	const std::string& GetRelationshipStatus() const { return relationship_status_; }
	const std::string& GetReligion() const { return religion_; }
	const std::string& GetPolitical() const { return political_; }
	const std::string& GetVerified() const { return verified_; }
	const std::string& GetSignificantOther() const { return significant_other_; }
	float GetTimezone() const { return timezone_; }

	//----------------------------------------------
	// Connections
	void GetHomeConnection(std::list<PolymorphicObject> *list, const PagingInfo *paging = NULL) const;
	void GetFeedConnection(std::list<PolymorphicObject> *list, const PagingInfo *paging = NULL) const;
	void GetTaggedConnection(std::list<Photo> *list, const PagingInfo *paging = NULL) const;
	void GetPostsConnection(std::list<Post> *list, const PagingInfo *paging = NULL) const;
	void GetPictureConnection(PictureSize size, ResponseBlob *blob) const;
	void GetFriendsConnection(std::list<Friend> *list, const PagingInfo *paging = NULL) const;
	void GetActivitiesConnection(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetInterestsConnection(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetMusicConnection(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetBooksConnection(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetMoviesConnection(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetTelevisionConnection(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetLikesConnection(std::list<From> *list, const PagingInfo *paging = NULL) const;
	void GetPhotosConnection(std::list<Photo> *list, const PagingInfo *paging = NULL) const;
	void GetAlbumsConnection(std::list<Album> *list, const PagingInfo *paging = NULL) const;
	void GetVideosConnection(std::list<Video> *list, const PagingInfo *paging = NULL) const;
	void GetGroupsConnection(std::list<Group> *list, const PagingInfo *paging = NULL) const;
	void GetStatusesConnection(std::list<Status> *list, const PagingInfo *paging = NULL) const;
	void GetLinksConnection(std::list<Link> *list, const PagingInfo *paging = NULL) const;
	void GetNoteConnection(std::list<Note> *list, const PagingInfo *paging = NULL) const;
	void GetEventsConnection(std::list<Event> *list, const PagingInfo *paging = NULL) const;
	void GetInboxConnection(std::list<Message> *list, const PagingInfo *paging = NULL) const;
	void GetOutboxConnection(std::list<Message> *list, const PagingInfo *paging = NULL) const;
	void GetUpdatesConnection(std::list<Message> *list, const PagingInfo *paging = NULL) const;
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
	Location hometown_;
	Location location_;
	std::string gender_;
	std::list<std::string> interested_in_;
	std::string meeting_for_;
	std::string relationship_status_;
	std::string religion_;
	std::string political_;
	std::string verified_;
	std::string significant_other_;
	float timezone_;
};

} // namespace LibFacebookCpp

#endif

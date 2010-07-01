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

class Album;
class Photo;
struct PagingInfo;

class FACEBOOK_API Location : public AuthorizedObject
{
public: // public interface
	void Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) FACEBOOK_OVERRIDE;

public: // accessors
	const std::string& GetId() const   { return id_; }
	const std::string& GetName() const { return name_; }

private: // member variables
	std::string id_;
	std::string name_;
};

class FACEBOOK_API FriendContainer: public AuthorizedObject
{
public:
	//----------------------------------------------
	FriendContainer(){};

	// XXX: Make this private, somehow

	//----------------------------------------------
	void Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) FACEBOOK_OVERRIDE;

	//----------------------------------------------
	const std::string& getName();
	const std::string& getID();

private:
	std::string name_;
	std::string id_;
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
	void Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) FACEBOOK_OVERRIDE;

	//----------------------------------------------
	//Getters
	const std::string& getId() const { return id_; }
	const std::string& getFirstName() const { return first_name_; }
	const std::string& getLastName() const { return last_name_; }
	const std::string& getName() const { return name_; }
	const std::string& getLink() const { return link_; }
	const std::string& getAbout() const { return about_; }
	const std::string& getBirthday() const { return birthday_; }
	const std::string& getWork() const { return work_; }
	const std::string& getEducation() const { return education_; }
	const std::string& getEmail() const { return email_; }
	const std::string& getWebsite() const { return website_; }
	const Location& getHomeTown() const { return hometown_; }
	const Location& getLocation() const { return location_; }
	const std::string& getGender() const { return gender_; }
	const std::list<std::string>& getInterestedIn() const { return interested_in_; }
	const std::string& getMeetingFor() const { return meeting_for_; }
	const std::string& getRelationshipStatus() const { return relationship_status_; }
	const std::string& getReligion() const { return religion_; }
	const std::string& getPolitical() const { return political_; }
	const std::string& getVerified() const { return verified_; }
	const std::string& getSignificantOther() const { return significant_other_; }
	int getTimeZone() const { return timezone_; }

	//----------------------------------------------
	// Connections
	// TODO: /home
	// TODO: /feed
	void getTaggedList(std::list<Photo> *photoList, const PagingInfo *paging = NULL) const;
	// TODO: /posts
	// TODO: /picture
	void getFriendsList(std::list<FriendContainer>* friendList, const PagingInfo *paging = NULL) const;
	// TODO: /activities
	// TODO: /interests
	// TODO: /music
	// TODO: /books
	// TODO: /movies
	// TODO: /television
	// TODO: /likes
	void getPhotosList(std::list<Photo> *photoList, const PagingInfo *paging = NULL) const;
	void getAlbumsList(std::list<Album> *albumList, const PagingInfo *paging = NULL) const;
	// TODO: /videos
	// TODO: /groups
	// TODO: /statuses
	// TODO: /links
	// TODO: /notes
	// TODO: /events
	// TODO: /inbox
	// TODO: /outbox
	// TODO: /updates
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
	int timezone_;
};

} // namespace Facebook

#endif

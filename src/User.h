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
	class FACEBOOK_API FriendContainer: public AuthorizedObject
	{
	public:
		//----------------------------------------------
		FriendContainer(){};

		//----------------------------------------------
		void Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) OVERRIDE;

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
		void Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) OVERRIDE;

		User* clone() const;

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
		// const std::string& getHometown() const { return hometown_; }
		const std::string& getGender() const { return gender_; }
		const std::string& getInterestedIn() const { return interested_in_; }
		const std::string& getMeetingFor() const { return meeting_for_; }
		const std::string& getRelationshipStatus() const { return relationship_status_; }
		const std::string& getReligion() const { return religion_; }
		const std::string& getPolitical() const { return political_; }
		const std::string& getVerified() const { return verified_; }
		const std::string& getSignificantOther() const { return significant_other_; }
		const std::string& getTimeZone() const { return timezone_; }

		//----------------------------------------------
		// Connections
		void getFriendsList(int offSet, int limit, std::list<FriendContainer>& friendList) const;

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
		// std::string hometown_;
		std::string gender_;
		std::string interested_in_;
		std::string meeting_for_;
		std::string relationship_status_;
		std::string religion_;
		std::string political_;
		std::string verified_;
		std::string significant_other_;
		std::string timezone_;

	};

}

#endif

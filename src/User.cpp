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

namespace Facebook
{
	void Facebook::FriendContainer::Deserialize(const Json::Value &json)
	{
		Deserializer deserialize(*this, json);

		deserialize.Deserialize("id", false, &id_);
		deserialize.Deserialize("name", false, &name_);
	}


	void Facebook::User::Deserialize( const Json::Value &json )
	{
		Deserializer deserialize(*this, json);

		// XXX: Fix the commented fields
		deserialize.Deserialize("id", false, &id_);
		deserialize.Deserialize("first_name", false, &first_name_);
		deserialize.Deserialize("last_name", false, &last_name_);
		deserialize.Deserialize("name", false, &name_);
		deserialize.Deserialize("link", false, &link_);
		deserialize.Deserialize("about", false, &about_);
		deserialize.Deserialize("birthday", false, &birthday_);
		deserialize.Deserialize("work", false, &work_);
		deserialize.Deserialize("email", false, &email_);
		deserialize.Deserialize("website", false, &website_);
		// deserialize.Deserialize("hometown", false, &hometown_);
		deserialize.Deserialize("gender", false, &gender_);
		// deserialize.Deserialize("interested_in", false, &interested_in_);
		deserialize.Deserialize("meeting_for", false, &meeting_for_);
		deserialize.Deserialize("relationship_status", false, &relationship_status_);
		deserialize.Deserialize("religion", false, &religion_);
		deserialize.Deserialize("political", false, &political_);
		deserialize.Deserialize("verified", false, &verified_);
		deserialize.Deserialize("significant_other", false, &significant_other_);
		// deserialize.Deserialize("timezone", false, &timezone_);

	}

	User* User::clone() const // probably wont' need this depending how large this object is
	{ 
		// do a deep copy
		shared_ptr<HttpRequest> clonedRequest_ = GetHttpRequest();
		Facebook::User* clonedUser = new Facebook::User();

		clonedUser->id_ = id_;
		clonedUser->first_name_ =first_name_;
		clonedUser->last_name_ = last_name_;
		clonedUser->name_ = name_;
		clonedUser->link_ = link_;
		clonedUser->about_ = about_;
		clonedUser->birthday_ = birthday_;
		clonedUser->work_ = work_;
		clonedUser->email_ = email_;
		clonedUser->website_ = website_;
		// clonedUser->hometown_ = hometown_;
		clonedUser->gender_ = gender_;
		clonedUser->interested_in_ = interested_in_;
		clonedUser->meeting_for_ = meeting_for_;
		clonedUser->relationship_status_ = relationship_status_;
		clonedUser->religion_ = religion_;
		clonedUser->political_ = political_;
		clonedUser->verified_ = verified_;
		clonedUser->significant_other_ = significant_other_;
		clonedUser->timezone_ = timezone_;

		return clonedUser;
	}

	void Facebook::User::getFriendsList( std::list<FriendContainer>& friendList ) const
	{
		Facebook::Uri friendLink;

		friendLink.base_uri = "https://graph.facebook.com/" + id_ + "/friends";

		friendLink.query_params["access_token"] = GetHttpRequest()->getAccessToken();

		Json::Value userValues;
		Deserializer deserializer(*this, userValues);
		GetHttpRequest()->GetResponse(friendLink, userValues);

		deserializer.Deserialize("data", false, &friendList);

	}
}
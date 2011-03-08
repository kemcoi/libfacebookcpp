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

#ifndef LIBFACEBOOKCPP_SESSION_H_
#define LIBFACEBOOKCPP_SESSION_H_

#include "AuthorizedObject.hpp"
#include "ExtendedPermissions.hpp"

namespace LibFacebookCpp
{

class User;
class HttpRequest;

class LIBFACEBOOKCPP_API Session : public AuthorizedObject
{
	friend class std::auto_ptr<Session>;
public:
	Session(const std::string& redirectedURL);
	~Session();
	//----------------------------------------------
	/*! 
	// You must call this to receive the authentication URL
	// This URL must be accepted by the user in order to retrieve 
	// the access token. */
	// XXX: This exnteded permissions should be boost::optional, instead of creating an empty pod
	static const std::string GetAuthenticationURL(const std::string& clientID,
												  const std::string& redirectURI,
												  const std::string& type,
												  const std::string& display,
												  const boost::optional<const ExtendedPermissions&> &scope = boost::none_t());

	//----------------------------------------------
	// Getters

	void GetCurrentUser(User *user) const;
	void GetUserById(const std::string& userID, User *user) const;

	// Connections
	// XXX: What does this call return?
	// XXX: A struct for coordinates
	// XXX: How should the list be?
	void CreateCheckin(const std::string &longitude, const std::string &latitude, const std::string &place_id, const boost::optional<const std::list<const std::string>&> &tags, const boost::optional<std::string&>& message);

private:
	// stick this as private to avoid being called
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

	DISALLOW_COPY_AND_ASSIGN(Session);
};

} // namespace LibFacebookCpp

#endif LIBFACEBOOKCPP_SESSION_H_

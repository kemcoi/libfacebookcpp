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

#ifndef FACEBOOK_SESSION_H_
#define FACEBOOK_SESSION_H_

#include "AuthorizedObject.h"
//#include "ExtendedPermissions.h"

namespace LibFacebookCpp
{

class User;
class HttpRequest;

class LIBFACEBOOKCPP_API Session : public AuthorizedObject
{
	friend class std::auto_ptr<Session>;
public:
	//----------------------------------------------
	/*! 
	// You must call this to receive the authentication URL
	// This URL must be accepted by the user in order to retrieve 
	// the access token. */
	static const std::string GetAuthenticationURL(const std::string& clientID, 
												  const std::string& redirectURI,
												  const std::string& type, 
												  const std::string& display,
												  const std::list<std::string>& scope);

	//----------------------------------------------
	/*!
	// The caller is given ownership of a Facebook::Session object
	// based on the access token that is passed in. */
	static Session* Authenticate(std::string& redirectedURL);

	//----------------------------------------------
	/*!
	// This method should be used to destroy Facebook::Session objects*/
	void Destroy();

	//----------------------------------------------
	// Getters

	void GetCurrentUser(User *user);
	void GetUserById(const std::string& userID, User *user);

private:

	// stick this as private to avoid being called
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);
	Session(const std::string& accessToken);
	~Session();

	DISALLOW_COPY_AND_ASSIGN(Session);
};

} // namespace LibFacebookCpp

#endif


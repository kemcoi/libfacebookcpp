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

#include "Session.h"

#include "HTTPRequest.h"
#include "User.h"
#include "Exception.h"
#include "Photo.h"

namespace Facebook
{

//----------------------------------------------
// Constructor
Session::Session(const std::string& accessToken)
{
	GetInfoLog() << "Initializing Session";
	// logger_ = new Facebook::Logger();
	Init(shared_ptr<HttpRequest>(new HttpRequest(accessToken)));
	GetInfoLog() << "User session created with access token:" << accessToken << std::endl;
	
}
//----------------------------------------------
void Session::Destroy()
{
	delete this;
}

//----------------------------------------------
Facebook::Session::~Session()
{
	GetInfoLog() << "Destroying user session" << std::endl;
}

//----------------------------------------------
const std::string Session::GetAuthenticationURL(const std::string& clientID,
												const std::string& redirectURI,
												const std::string& type, 
												const std::string& display,
												const std::list<std::string>& scope)
{
	GetInfoLog() << "Creating Authentication URL" << std::endl;
	Facebook::Uri authenticationURL;
	authenticationURL.base_uri = "https://graph.facebook.com/oauth/authorize";

	authenticationURL.query_params["client_id"] = clientID;
	authenticationURL.query_params["redirect_uri"] = redirectURI;

	if(!type.empty())
	{	
		authenticationURL.query_params["type"] = type;
	}

	if(!display.empty())
	{
		authenticationURL.query_params["display"] = display;
	}

	// TODO: Make this easier
	std::stringstream oss;
	for(std::list<std::string>::const_iterator iter = scope.begin();iter != scope.end(); iter++)
	{
		oss<<*iter;
		if(iter != (--scope.end()))
		{
			 oss << ',';
		}
	}

	if(!scope.empty())
	{
		authenticationURL.query_params["scope"] = oss.str();
	}

	return authenticationURL.GetUri();
}

//----------------------------------------------
Session* Session::Authenticate(std::string& redirectedURL)
{	
	// XXX: Hack
	redirectedURL[redirectedURL.find_first_of('#')] = '?';

	Facebook::Uri redirectedParams;
	HttpUtils::DecomposeUri(redirectedURL, redirectedParams); // THANK YOU ALY

	Uri::QueryParamMap::const_iterator it = redirectedParams.query_params.find("access_token");

	if(it == redirectedParams.query_params.end())
	{
		GetWarnLog() << "No access_token found" << std::endl;
		throw UnexpectedException("Unable to find access token from redirected URL");
	}
	else
	{
		GetInfoLog() << "Found Access Token"  << std::endl;
		return new Facebook::Session(it->second);
	}	
}

//----------------------------------------------
void Session::GetCurrentUser(User *user)
{
	GetConnection("https://graph.facebook.com/me", user);
}

//----------------------------------------------
void Session::GetUserById(const std::string& userID, User *user)
{
	// XXX: URL Encode userid
	GetConnection("https://graph.facebook.com/" + userID, user);
}

void Session::_Deserialize(const AuthorizedObject & /* parent_obj */, const Json::Value & /* json */)
{
	throw UnexpectedException("Session::_Deserialize");
}
//----------------------------------------------

} // namespace Facebook

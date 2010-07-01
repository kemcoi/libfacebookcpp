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

namespace Facebook
{

//----------------------------------------------
// Constructor
Session::Session(const std::string& accessToken): cachedUser_(NULL)
{
	GetInfoLog() << "Initializing Session";
	// logger_ = new Facebook::Logger();
	request_ = shared_ptr<HttpRequest>(new HttpRequest(accessToken));
	GetInfoLog() << accessToken;
	
}
//----------------------------------------------
void Session::Destroy()
{
	delete this;
}

//----------------------------------------------
Facebook::Session::~Session()
{
	delete cachedUser_; cachedUser_ = NULL;
	// delete logger_; logger_ = NULL;
}

//----------------------------------------------
const std::string Session::GetAuthenticationURL(const std::string& clientID,
												const std::string& redirectURI,
												const std::string& type, 
												const std::string& display)
{
	GetInfoLog() << "Creating Authentication URL";
	
	static const char *authorization_uri = "https://graph.facebook.com/oauth/authorize";
	std::stringstream oss;

	oss << authorization_uri << "?client_id=" << curlpp::escape(clientID) << "&redirect_uri=" <<
		curlpp::escape(redirectURI); 

	if(!type.empty())
	{	
		oss << "&type=" << curlpp::escape(type) ;
	}

	if(!display.empty())
	{
		oss<< "&display=" << curlpp::escape(display);
	}

	return oss.str();
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
		GetWarnLog() << "No access_token found";
		throw UnexpectedException("Unable to find access token from redirected URL");
	}
	else
	{
		GetInfoLog() << "Found Access Token";
		return new Facebook::Session(it->second);
	}	
}

//----------------------------------------------
const Facebook::User* Session::getCurrentUser()
{
	// W00t for ugly code
	const Facebook::User* newUser = getUserByID("me");

	// let's keep a copy on our session object
	if( NULL == cachedUser_)
	{
		cachedUser_ = newUser->clone();
	}
	return newUser;
}

//----------------------------------------------
const Facebook::User* Session::getUserByID( const std::string& userID )
{
	Facebook::User* newUser = new Facebook::User();
	Facebook::Uri userLink;
	GetHttpRequest()->GetUri(&userLink);

	userLink.base_uri = "https://graph.facebook.com/" + userID;

	Json::Value userValues;

	GetHttpRequest()->GetResponse(userLink, userValues);
	newUser->Deserialize(*this, userValues);

	return newUser;
}
//----------------------------------------------

} // namespace Facebook

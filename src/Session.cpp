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

#include "precompile.hpp"

#include "Session.hpp"

#include "HTTPRequest.hpp"
#include "User.hpp"
#include "Exception.hpp"
#include "Photo.hpp"

namespace LibFacebookCpp
{

//----------------------------------------------
// Constructor

Session::Session(const std::string& redirectedUri)
{
	// Facebook returns us the params we need to parse in the # fragment section of the URL
	// However, Facebook encodes it in the exact same fashion as you'd encode query parameters.
	// So, in order to parse this, we'd typically just parse them as query parameters key-pair values
	// The easiest and hack-ish way to do is to change the '#' character into a '?' character.
	// However, since the redirectedURL is a custom URL, it might actually have a set of query parameters
	// In this case, we do this. Strip the part of the string between ? and the #, convert the '#' to a '?'
	// and then Decompose the Uri. In this case, it allows us to extract the params easily.

	std::string decomposeUri;
	std::string::size_type idxQueryParam = redirectedUri.find_first_of("?");
	std::string::size_type idxAnchor = redirectedUri.find_first_of("#");

	LIBFACEBOOKCPP_CHKARG(std::string::npos != idxAnchor);

	if(std::string::npos != idxQueryParam)
	{
		LIBFACEBOOKCPP_CHKARG(idxQueryParam < idxAnchor);

		// We have a part of the query parameters in the string. We need to strip it
		decomposeUri = redirectedUri;
		decomposeUri.erase(idxQueryParam, idxAnchor - idxQueryParam);
		decomposeUri[idxQueryParam] = '?';
	}
	else
	{
		// We don't have any query parameters in the string. Great, just copy over the string
		decomposeUri = redirectedUri;
		decomposeUri[idxAnchor] = '?';
	}

	Uri redirectedParams;
	HttpUtils::DecomposeUri(decomposeUri, &redirectedParams); // THANK YOU ALY

	Uri::QueryParamMap::const_iterator it = redirectedParams.query_params.find("access_token");

	if(it == redirectedParams.query_params.end())
	{
		GetWarnLog() << "No access_token found" << std::endl;
		throw UnexpectedException("Unable to find access token from redirected URL");
	}
	else
	{
		// GetInfoLog() << "Found Access Token"  << std::endl;
		Init(shared_ptr<HttpRequest>(new HttpRequest(it->second)));
	}
}

Session::Session(const Session& rhs)
{
	*this = rhs;
}

Session& Session::operator=(const Session& rhs)
{
	if(&rhs == this)
		return *this;

	// XXX: This will crash
	Init(shared_ptr<HttpRequest>(new HttpRequest(*rhs.request_)));
}

//----------------------------------------------
Session::~Session()
{
	// GetInfoLog() << "Destroying user session" << std::endl;
}

//----------------------------------------------
const std::string Session::GetAuthenticationURL(const std::string& clientID,
												const std::string& redirectURI,
												const std::string& type, 
												const std::string& display,
												const ExtendedPermissions& scope /* = ExtendedPermissions() */)
{
	// GetInfoLog() << "Creating Authentication URL" << std::endl;
	Uri authenticationURL;
	authenticationURL.base_uri = "https://graph.facebook.com/oauth/authorize";

	authenticationURL.query_params["client_id"] = clientID;
	authenticationURL.query_params["redirect_uri"] = redirectURI;

	// XXX: Should these be enums?
	if(!type.empty())
	{	
		authenticationURL.query_params["type"] = type;
	}

	if(!display.empty())
	{
		authenticationURL.query_params["display"] = display;
	}

	if(scope.PermissionsRequested())
	{
		authenticationURL.query_params["scope"]  = scope.GetPermissionsString();
	}

	return authenticationURL.GetUri();
}

//----------------------------------------------
void Session::GetCurrentUser(User *user)
{
	_GetConnection("me", "", user);
}

//----------------------------------------------
void Session::GetUserById(const std::string& userID, User *user)
{
	_GetConnection(userID, "", user);
}

void Session::_Deserialize(const AuthorizedObject & /* parent_obj */, const Json::Value & /* json */)
{
	throw UnexpectedException("Session::_Deserialize");
}

} // namespace LibFacebookCpp

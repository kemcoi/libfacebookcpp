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
 *
 */

#include "Session.h"
#include "HTTPRequest.h"

#include <iostream>

int main()
{
	/*Facebook::HttpRequest req;
	req.SetUrl("");

	std::auto_ptr<Json::Value> val = req.GetResponse();

	Facebook::Photo *photo = new Facebook::Photo();

	photo->Deserialize(*val);

	delete photo;*/

// 	Facebook::Session* session = Facebook::Session::getSession();
// 
// 	session;

	// let's use this for now
	std::string	clientid = "232486072316";
	std::string redirectURI = "http://www.facebook.com/connect/login_success.html";
	std::string url = Facebook::Session::GetAuthenticationURL(clientid, redirectURI, std::string(), std::string());

	std::string redirectURL = "http://www.facebook.com/connect/login_success.html?code=2.sU5pVytL4Pz3DCy0h9i3kw__.86400.1277056800-100000189955997|7DCCiMAJR75W_KgzwoFs406S2SQ.";
	Facebook::Session::Authenticate(redirectURL);

	system("pause"); // VS Debug
	return 0;
}
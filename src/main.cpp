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
#include "MemoryTracker.h"

#include <iostream>

int main()
{
	/*Facebook::HttpRequest req;
	req.SetUrl("");

	std::auto_ptr<Json::Value> val = req.GetResponse();

	Facebook::Photo *photo = new Facebook::Photo();

	photo->Deserialize(*val);

	delete photo;*/

	BeginMemoryTracker();

	{
		// let's use this for now
		std::string	clientid = "232486072316";
		std::string redirectURI = "http://www.facebook.com/connect/login_success.html";
		std::string url = Facebook::Session::GetAuthenticationURL(clientid, redirectURI, "user_agent", std::string());

		std::cout << "PASTE THIS INTO YOUR BROWSER TO ACCEPT" << std::endl;
		std::cout<<std::endl << url << std::endl;
		std::string redirectURL;
		system("pause"); // VS Debug

		std::cout << "COPY THE REDIRECTED URL INTO HERE";
		std::cin >> redirectURL;

		std::auto_ptr<Facebook::Session> session_(Facebook::Session::Authenticate(redirectURL));
		std::auto_ptr<const Facebook::User> user_(session_->getCurrentUser());
	
		std::auto_ptr<const Facebook::User> jonLai(session_->getUserByID(std::string("506828136")));
		system("pause"); // VS Debug
	}

	EndMemoryTracker();

	return 0;
}
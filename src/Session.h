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

#ifndef FACEBOOK_SESSION_H_
#define FACEBOOK_SESSION_H_

// Aggregate include's here
#include "Common.h"
#include "From.h"
#include "User.h"
#include "Albums.h"
#include "Photo.h"
#include "Logger.h"



namespace Facebook
{
	class Session
	{
	public:
		//----------------------------------------------
		// You must call this to recieve the authentication URL
		// This URL must be accepted to 
		static const std::string GetAuthenticationURL(const std::string clientID, 
											   const std::string redirectURI,
											   const std::string type, 
											   const std::string display);

		//----------------------------------------------
		// 
		static Session* Authenticate(std::string redirectedURL);
		//----------------------------------------------
		void Destroy();

		//----------------------------------------------
		// Getters
		const Facebook::User* getCurrentUser();




	private:
		Session(std::string accessToken);
		~Session();

		Facebook::Logger* logger_;
		HttpRequest* HtppHandler_;

		Facebook::User* cachedUser_;
	};
}

#endif


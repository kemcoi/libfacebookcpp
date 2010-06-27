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

#ifndef FACEBOOK_STATUS_H_
#define FACEBOOK_STATUS_H_

#include "From.h"

namespace Facebook
{
	class FACEBOOK_API Status : public AuthorizedObject
	{
	public:
		//----------------------------------------------
		Status() { }
		virtual ~Status() { }

		//----------------------------------------------
		void Deserialize(const Json::Value &json) OVERRIDE;

		//----------------------------------------------
		// Accessors
		//TODO: Accessors for From class
		const std::string& getId() const { return id_; }
		const From& GetFrom() const { return from_; }
	private:
		std::string id_;
		From from_;
		std::string message_;
		std::string updated_time_;
	};
}

#endif


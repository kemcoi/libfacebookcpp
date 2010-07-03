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


#ifndef FACEBOOK_MESSAGE_H
#define FACEBOOK_MESSAGE_H

#include "AuthorizedObject.h"
#include "To.h"
#include "From.h"

namespace Facebook
{

class FACEBOOK_API Message: public AuthorizedObject
{

public: // accessors
	const std::string& Id() const { return id_; }
	const From& From() const { return from_; }
	const To& To() const {return to_; }
	const std::string& MessageContents() const { return message_; }
	const std::string& UpdatedTime() const { return updated_time_; }

protected:
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) FACEBOOK_OVERRIDE;

private: // member variables 
	std::string id_;
	Facebook::From from_;
	Facebook::To to_;
	std::string message_;
	std::string updated_time_;

};

}

#endif
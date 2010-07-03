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

#include "AuthorizedObject.h"
#include "From.h"

#ifndef FACEBOOK_NOTE_H
#define FACEBOOK_NOTE_H

namespace Facebook
{

class Comment;

class FACEBOOK_API Note: public AuthorizedObject
{
public: // accessors
	const std::string& Id() const { return id_; }
	const Facebook::From& From() const { return from_; }
	const std::string& Subject() const { return subject_; }
	const std::string& Message() const { return message_; }
	const std::string& CreatedTime() const { return created_time_; }
	const std::string& UpdatedTime() const { return updated_time_; }

	void GetComments(std::list<Comment> *list, const PagingInfo *paging = NULL);

protected:
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string id_;
	Facebook::From from_;
	std::string subject_;
	std::string message_;
	std::string created_time_;
	std::string updated_time_;
};

}

#endif
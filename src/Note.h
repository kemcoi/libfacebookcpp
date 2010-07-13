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

#ifndef FACEBOOK_NOTE_H
#define FACEBOOK_NOTE_H

#include "AuthorizedObject.h"
#include "From.h"

namespace LibFacebookCpp
{

class Comment;

class LIBFACEBOOKCPP_API Note: public AuthorizedObject
{
public: // accessors
	const std::string& GetId() const { return id_; }
	const From& GetFrom() const { return from_; }
	const std::string& GetSubject() const { return subject_; }
	const std::string& GetMessage() const { return message_; }
	const DateTime& GetCreatedTime() const { return created_time_; }
	const DateTime& GetUpdatedTime() const { return updated_time_; }

	void GetComments(std::list<Comment> *list, const PagingInfo *paging = NULL);

protected:
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string id_;
	From from_;
	std::string subject_;
	std::string message_;
	DateTime created_time_;
	DateTime updated_time_;
};

} // namespace LibFacebookCpp

#endif // FACEBOOK_NOTE_H_

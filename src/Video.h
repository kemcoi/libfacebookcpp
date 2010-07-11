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

#ifndef FACEBOOK_VIDEO_H_
#define FACEBOOK_VIDEO_H_

#include "AuthorizedObject.h"
#include "From.h"
#include "DateTime.h"

namespace Facebook
{

class Comment;

class FACEBOOK_API Video : public AuthorizedObject
{
public: // accessors
	const std::string& Id() const { return id_; }
	// XXX: Rename from
	const From& From() const { return from_; }
	const std::string& Message() const { return message_; }
	const std::string& Description() const { return description_; }
	unsigned int Length() const { return length_; }
	const DateTime& CreatedTime() const { return created_time_; }
	const DateTime& UpdatedTime() const { return updated_time_; }

public: // connections
	void GetComments(std::list<Comment> *list, const PagingInfo *paging = NULL) const;

protected:
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) FACEBOOK_OVERRIDE;

private: // member variables
	std::string id_;
	Facebook::From from_;
	std::string message_;
	std::string description_;
	// XXX: int64?
	unsigned int length_;
	DateTime created_time_;
	DateTime updated_time_;
};

} // namespace Facebook

#endif // FACEBOOK_VIDEO_H_

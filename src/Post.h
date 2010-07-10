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
#include "DateTime.h"

namespace Facebook
{

class Comment;

class FACEBOOK_API Post : public AuthorizedObject
{
public: // accessors
	const std::string& Id() const { return id_; }
	const Facebook::From& From() const { return from_; }
	const std::list<std::string>& To() const { return to_; }
	const std::string& Message() const { return message_; }
	const std::string& Picture() const { return picture_; }
	const std::string& Link() const { return link_; }
	const std::string& Name() const { return name_; }
	const std::string& Caption() const { return caption_; }
	const std::string& Description() const { return description_; }
	const std::string& Source() const { return source_; }
	const std::string& Icon() const { return icon_; }
	const std::string& Attribution() const { return attribution_; }
	const std::list<std::string>& Actions() const { return actions_; }
	unsigned int Likes() const { return likes_; }
	const DateTime& CreatedTime() const { return created_time_; }
	const DateTime& UpdatedTime() const { return updated_time_; }

public: // connections
	void GetComments(std::list<Comment> *list, const PagingInfo *paging = NULL);

protected:
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string id_;
	Facebook::From from_;
	std::list<std::string> to_;
	std::string message_;
	std::string picture_;
	std::string link_;
	std::string name_;
	std::string caption_;
	std::string description_;
	std::string source_;
	std::string icon_;
	std::string attribution_;
	std::list<std::string> actions_;
	// XXX: uint64
	unsigned int likes_;
	DateTime created_time_;
	DateTime updated_time_;
};

} // namespace Facebook
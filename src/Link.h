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

#ifndef LIBFACEBOOKCPP_LINK_H_
#define LIBFACEBOOKCPP_LINK_H_

#include "AuthorizedObject.h"
#include "Friend.h"
#include "DateTime.h"

namespace LibFacebookCpp
{

class Comment;

class LIBFACEBOOKCPP_API Link : public AuthorizedObject
{
public: // accessors
	const std::string& GetId() const { return id_; }
	const Friend& GetFrom() const { return from_; }
	const std::string& GetLink() const { return link_; }
	const std::string& GetName() const { return name_; }
	const std::string& GetCaption() const { return caption_; }
	const std::string& GetDescription() const { return description_; }
	const std::string& GetMessage() const { return message_; }
	const DateTime& GetUpdatedTime() const { return updated_time_; }

public: // connection
	// XXX: Make sure all connections are const
	void GetComments(List<Comment> *list, const PagingInfo *paging = NULL) const;

	// XXX: comment callback
protected: // callback functions
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string id_;
	Friend from_;
	std::string link_;
	std::string name_;
	std::string caption_;
	std::string description_;
	std::string message_;
	DateTime updated_time_;
};

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_LINK_H_

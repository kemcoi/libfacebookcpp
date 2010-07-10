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

namespace LibFacebookCpp
{

class Comment;

class LIBFACEBOOKCPP_API Post : public AuthorizedObject
{
public: // accessors
	const std::string& GetId() const { return id_; }
	const From& GetFrom() const { return from_; }
	const std::list<std::string>& GetTo() const { return to_; }
	const std::string& GetMessage() const { return message_; }
	const std::string& GetPicture() const { return picture_; }
	const std::string& GetLink() const { return link_; }
	const std::string& GetName() const { return name_; }
	const std::string& GetCaption() const { return caption_; }
	const std::string& GetDescription() const { return description_; }
	const std::string& GetSource() const { return source_; }
	const std::string& GetIcon() const { return icon_; }
	const std::string& GetAttribution() const { return attribution_; }
	const std::list<std::string>& GetActions() const { return actions_; }
	unsigned int GetLikes() const { return likes_; }
	const DateTime& GetCreatedTime() const { return created_time_; }
	const DateTime& GetUpdatedTime() const { return updated_time_; }

public: // connections
	void GetComments(std::list<Comment> *list, const PagingInfo *paging = NULL);

protected:
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string id_;
	From from_;
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

} // namespace LibFacebookCpp
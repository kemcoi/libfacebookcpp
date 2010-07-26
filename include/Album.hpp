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

#ifndef LIBFACEBOOKCPP_ALBUM_H_
#define LIBFACEBOOKCPP_ALBUM_H_

#include "AuthorizedObject.hpp"
#include "From.hpp"
#include "DateTime.hpp"

namespace LibFacebookCpp
{

class Photo;
class Comment;

class LF_API Album: public AuthorizedObject
{
public:
	//----------------------------------------------
	Album() { }
	virtual ~Album() { }

	//----------------------------------------------
	// Accessors
	const std::string& GetId() const { return id_; }
	const From& GetFrom() const { return from_; }
	const std::string& GetName() const { return name_; }
	const std::string& GetDescription() const { return description_; }
	const std::string& GetLocation() const { return location_; }
	const std::string& GetLink() const { return link_; }
	unsigned int GetCount() const { return count_; }
	const DateTime& GetCreatedTime() const { return created_time_;}
	const DateTime& GetUpdatedTime() const { return updated_time_; }

	//----------------------------------------------
	// Connections
	void GetPhotosConnection(List<Photo> *list, const PagingInfo *paging = NULL) const;
	void GetCommentsConnection(List<Comment> *list, const PagingInfo *paging = NULL) const;

private:
	//----------------------------------------------
	// Callbacks
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) LF_OVERRIDE;

private:
	std::string id_;
	From from_;
	std::string name_;
	std::string description_;
	std::string location_;
	std::string link_;
	unsigned int count_;
	DateTime created_time_;
	DateTime updated_time_;
};

} // namespace LibFacebookCpp

#endif
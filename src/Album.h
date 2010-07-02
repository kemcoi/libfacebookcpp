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

#ifndef FACEBOOK_ALBUM_H_
#define FACEBOOK_ALBUM_H_

#include "AuthorizedObject.h"
#include "From.h"

namespace Facebook
{

class Photo;

class FACEBOOK_API Album: public AuthorizedObject
{
public:
	//----------------------------------------------
	Album() { }
	virtual ~Album() { }

	//----------------------------------------------
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) FACEBOOK_OVERRIDE;

	//----------------------------------------------
	// Accessors
	//TODO: Accessors for From class
	const std::string& Id() const { return id_; }
	const From& From() const { return from_; }
	const std::string& Name() const { return name_; }
	const std::string& Description() const { return description_; }
	const std::string& Location() const { return location_; }
	const std::string& Link() const { return link_; }
	const unsigned int& Count() const { return count_; }
	const std::string& CreatedTime() const { return created_time_;}
	const std::string& UpdatedTime() const { return updated_time_; }

private:
	std::string id_;
	Facebook::From from_;
	std::string name_;
	std::string description_;
	std::string location_;
	std::string link_;
	unsigned int count_;
	std::string created_time_;
	std::string updated_time_;
};

} // namespace Facebook

#endif
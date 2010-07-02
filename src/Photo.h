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

#ifndef FACEBOOK_PHOTO_H_
#define FACEBOOK_PHOTO_H_

#include "AuthorizedObject.h"
#include "From.h"

namespace Facebook
{

class FACEBOOK_API Photo : public AuthorizedObject
{
	typedef AuthorizedObject inherited;

public: // ctor and ~()
	Photo() { }
	virtual ~Photo() { }

public: // public interface
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) FACEBOOK_OVERRIDE;

	const std::string& Id() const { return id_; }
	const From& From() const { return from_; }
	const std::string& Name() const { return name_; }
	const std::string& Picture() const { return picture_; }
	const std::string& Source() const { return source_; }
	unsigned int Height() const { return height_; }
	unsigned int Width() const { return width_; }
	const std::string& Link() const { return link_; }
	const std::string& Icon() const { return icon_; }
	const std::string& CreatedTime() const { return created_time_; }
	const std::string& UpdatedTime() const { return updated_time_; }

private: // private members
	std::string id_;
	Facebook::From from_;
	std::string name_;
	std::string picture_;
	std::string source_;
	unsigned int height_;
	unsigned int width_;
	std::string link_;
	std::string icon_;
	std::string created_time_;
	std::string updated_time_;
};

} // namespace Facebook

#endif // FACEBOOK_PHOTO_H_

/*
 * Copyright (C) 2010-2011
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

#ifndef LIBFACEBOOKCPP_PHOTO_H_
#define LIBFACEBOOKCPP_PHOTO_H_

#include "AuthorizedObject.hpp"
#include "From.hpp"
#include "DateTime.hpp"

namespace LibFacebookCpp
{

class LIBFACEBOOKCPP_API Photo : public AuthorizedObject
{
	typedef AuthorizedObject inherited;

public: // ctor and ~()
	Photo() { }
	virtual ~Photo() { }

private:
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) LIBFACEBOOKCPP_OVERRIDE;

public: // public interface
	const std::string& GetId() const { return id_; }
	const From& GetFrom() const { return from_; }
	const std::string& GetName() const { return name_; }
	const std::string& GetPicture() const { return picture_; }
	const std::string& GetSource() const { return source_; }
	unsigned int GetHeight() const { return height_; }
	unsigned int GetWidth() const { return width_; }
	const std::string& GetLink() const { return link_; }
	const std::string& GetIcon() const { return icon_; }
	const DateTime& GetCreatedTime() const { return created_time_; }
	const DateTime& GetUpdatedTime() const { return updated_time_; }

private: // private members
	std::string id_;
	From from_;
	std::string name_;
	std::string picture_;
	std::string source_;
	unsigned int height_;
	unsigned int width_;
	std::string link_;
	std::string icon_;
	DateTime created_time_;
	DateTime updated_time_;
};

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_PHOTO_H_

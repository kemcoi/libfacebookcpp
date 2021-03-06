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

#ifndef LIBFACEBOOKCPP_VIDEO_H_
#define LIBFACEBOOKCPP_VIDEO_H_

#include "AuthorizedObject.hpp"
#include "From.hpp"

namespace LibFacebookCpp
{

class LIBFACEBOOKCPP_API Checkin : public AuthorizedObject
{
public: // accessors
	const std::string& GetId() const { return id_; }
	const From& GetFrom() const { return from_; }
	const std::string& GetMessage() const { return message_; }
	const DateTime& GetCreatedTime() const { return created_time_; }

private: // callbacks
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) LIBFACEBOOKCPP_OVERRIDE;

private: // member variables
	std::string id_;
	From from_;
	// XXX: How is tags/place listed?
	std::string message_;
	// XXX: How is the application listed
	// XXX: DateTime format changed?
	DateTime created_time_;
};

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_VIDEO_H_

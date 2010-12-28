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

#ifndef LIBFACEBOOKCPP_STATUS_H_
#define LIBFACEBOOKCPP_STATUS_H_

#include "AuthorizedObject.hpp"
#include "From.hpp"

namespace LibFacebookCpp
{

class LIBFACEBOOKCPP_API Status : public AuthorizedObject
{
public:
	//----------------------------------------------
	Status() { }
	virtual ~Status() { }

	//----------------------------------------------
	// Accessors
	const std::string& GetId() const { return id_; }
	const From& GetFrom() const { return from_; }
	const std::string& GetMessage() const { return message_; }
	const DateTime& GetUpdatedTime() const { return updated_time_; }

private:
	//----------------------------------------------
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) LIBFACEBOOKCPP_OVERRIDE;

private:
	std::string id_;
	From from_;
	std::string message_;
	DateTime updated_time_;
};

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_STATUS_H_

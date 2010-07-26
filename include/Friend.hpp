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

#ifndef LIBFACEBOOKCPP_FRIEND_CONTAINER_H_
#define LIBFACEBOOKCPP_FRIEND_CONTAINER_H_

#include "AuthorizedObject.hpp"

namespace LibFacebookCpp
{

class LF_API Friend: public AuthorizedObject
{
public:
	//----------------------------------------------
	Friend(){};

	// XXX: make all _deserialize private

	//----------------------------------------------
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) LF_OVERRIDE;

	//----------------------------------------------
	const std::string& Name() const { return name_; }
	const std::string& Id() const { return id_; }

private:
	std::string name_;
	std::string id_;
};

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_FRIEND_CONTAINER_H_

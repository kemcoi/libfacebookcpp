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

#ifndef LIBFACEBOOKCPP_LOCATION_H_
#define LIBFACEBOOKCPP_LOCATION_H_

#include "AuthorizedObject.hpp"

namespace LibFacebookCpp
{

class LIBFACEBOOKCPP_API Location : public AuthorizedObject
{
private: // public interface
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) LIBFACEBOOKCPP_OVERRIDE;

public: // accessors
	const std::string& GetId()   const   { return id_; }
	const std::string& GetName() const { return name_; }

private: // member variables
	std::string id_;
	std::string name_;
};

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_LOCATION_H_

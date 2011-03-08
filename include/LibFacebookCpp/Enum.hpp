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

#ifndef LIBFACEBOOKCPP_ENUM_H_
#define LIBFACEBOOKCPP_ENUM_H_

#include "AuthorizedObject.hpp"

namespace LibFacebookCpp
{

template<class T, T none, T count, const char *str_array[]>
class Enum : public AuthorizedObject
{
public: // ctor
	Enum() : t_(none) { }

public: // public interface
	operator T() const { return t_; }

private: // callback methods
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
	{
		if(!json.isConvertibleTo(Json::stringValue))
			throw UnexpectedException("!json.isConvertibleTo(Json::stringValue)");

		const std::string &str = json.asString();

		bool found = false;

		// Hack: This is nasty, but required to do a complete iteration. Hopefully, we never have to go over the int limit!
		for(int s = (int)none; s < (int)count; ++s)
		{
			if(stricmp(str.c_str(), str_array[s]) == 0)
			{
				t_ = (T)s;
				break;
			}
		}

		if(!found)
			throw UnexpectedException("!found");
	}

private: // member variables
	T t_;
};

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_ENUM_H_
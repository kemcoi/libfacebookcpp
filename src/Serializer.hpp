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

#ifndef LIBFACEBOOKCPP_SERIALIZER_H_
#define LIBFACEBOOKCPP_SERIALIZER_H_

namespace LibFacebookCpp
{

class Serializer
{
public: // interface
	template<class T>
	void Serialize(const char *key, const T &value);

	template<>
	void Serialize(const char *key, const std::string &str)
	{
		LIBFACEBOOKCPP_ASSERT(key);
		params.insert(std::make_pair(key, str));
	}

	const std::map<std::string, std::string>& GetParams() const { return params; }

private:
	std::map<std::string, std::string> params;
};

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_SERIALIZER_H_

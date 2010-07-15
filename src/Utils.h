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

#ifndef LIBFACEBOOKCPP_UTILS_H_
#define LIBFACEBOOKCPP_UTILS_H_

template<class TData>
inline std::string toString(const TData &t)
{
	std::ostringstream oss;
	oss << t;
	return oss.str();
}

template<class TData, class TStr>
inline TData fromString(const TStr &str)
{
	std::stringstream oss;
	oss << str;
	TData t;
	oss >> t;
	return t;
}

#endif // LIBFACEBOOKCPP_UTILS_H_
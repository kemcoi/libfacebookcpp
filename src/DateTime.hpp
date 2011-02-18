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

#ifndef LIBFACEBOOKCPP_DATE_TIME_H_
#define LIBFACEBOOKCPP_DATE_TIME_H_

namespace LibFacebookCpp
{

// This is just a simple wrapper around tm
struct LIBFACEBOOKCPP_API DateTime
{
public: // ctor
	DateTime() { memset(this, 0, sizeof(*this)); }

public: // interface
	void Parse(const std::string &str);

private: // member variables
	int year;
	int month;
	int date;
	int hour;
	int minute;
	int second;
	int offset;
};

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_DATE_TIME_H_

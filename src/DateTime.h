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

#ifndef FACEBOOK_DATETIME_H_
#define FACEBOOK_DATETIME_H_

namespace Facebook
{

// This is just a simple wrapper around tm
struct FACEBOOK_API DateTime
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

} // namespace Facebook

#endif // FACEBOOK_DATETIME_H_
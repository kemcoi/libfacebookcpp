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

#include "precompile.hpp"
#include "DateTime.hpp"
#include "Exception.hpp"

namespace LibFacebookCpp
{

void DateTime::Parse(const std::string &str)
{
	// Sample: "created_time": "2010-07-02T18:00:37+0000"

	char tz;
	int rt = sscanf(str.c_str(), "%d-%d-%dT%d:%d:%d%c%d", &year, &month, &date, &hour, &minute, &second, &tz, &offset);

	if(rt != 8 || (tz !='+' && tz != '-'))
	{
		memset(this, 0, sizeof(*this));
		throw InvalidArgument("str");
	}

	// offset is in HHMM. Convert it to fully minutes
	offset = offset % 100 + offset / 100 * 60;

	if(tz == '-')
		offset = -offset;
}

} // namespace LibFacebookCpp

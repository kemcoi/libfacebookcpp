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

#include "precompile.h"
#include "Logger.h"

namespace Facebook
{

Logger logInstance;

Logger::Logger()
{
	for(size_t ii = 0; ii < FACEBOOK_NUMELMS(stream_); ++ii)
	{
		stream_[ii].rdbuf(std::clog.rdbuf());
	}
}

std::ostream& Logger::GetStream( FB_LOGLEVEL level, int lineNumber, const char* file )
{
	FACEBOOK_ASSERT(level >= FB_LOGLEVEL_ERROR && level < FB_LOGLEVEL_COUNT);

	static const char *s_level[] = {
		"Error: ", "Warning: ", "Info: ", "Debug: "
	};

	FACEBOOK_CASSERT(FACEBOOK_NUMELMS(s_level) == FB_LOGLEVEL_COUNT);

	stream_[level] << std::endl << s_level[level];

	if(level <= FB_LOGLEVEL_WARN)
		stream_[level] << " @ " << file << ":" << lineNumber << std::endl;

	return stream_[level];
}

} // namespace Facebook

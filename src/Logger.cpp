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

#include "precompile.hpp"
#include "Logger.hpp"

namespace LibFacebookCpp
{

Logger logInstance;

Logger::Logger()
{
	// Only initialize streams for ERROR and WARN
	SetStream(LL_ERROR, std::cerr);
	SetStream(LL_WARN, std::cerr);
}

void Logger::SetStream(LogLevel level, std::ostream& stream)
{
	LIBFACEBOOKCPP_CHKARG(level < LL_ERROR || level >= LL_COUNT);

	stream_[level].rdbuf(stream.rdbuf());
}

std::ostream& Logger::GetStream(LogLevel level, int lineNumber, const char* file)
{
	LF_ASSERT(level >= LL_ERROR && level < LL_COUNT);

	static const char *s_level[] = {
		"Error: ", "Warning: ", "Info: ", "Debug: "
	};

	LIBFACEBOOKCPP_CASSERT(LIBFACEBOOKCPP_NUMELMS(s_level) == LL_COUNT);

	stream_[level] << std::endl << s_level[level];

	if(level <= LL_WARN)
		stream_[level] << " @ " << file << ":" << lineNumber << ": ";

	return stream_[level];
}

} // namespace LibFacebookCpp

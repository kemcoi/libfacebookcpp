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

#ifndef FACEBOOK_LOGGER_H_
#define FACEBOOK_LOGGER_H_

#include <ostream>

namespace Facebook
{
	class Logger;

	class LogStream : public std::ostream
	{
	private: // private ctor
		LogStream() : std::ostream(NULL)
		{
		}

		friend class Logger;
	};

	class Logger
	{
	public: // public types
		enum FB_LOGLEVEL
		{
			FB_LOGLEVEL_ERROR,
			FB_LOGLEVEL_WARN,
			FB_LOGLEVEL_INFO,
			FB_LOGLEVEL_DEBUG,

			FB_LOGLEVEL_COUNT
		};

	public: // public interface
		Logger();
		std::ostream& GetLog(FB_LOGLEVEL level, int lineNumber, const char* file);

	private:
		LogStream stream_[FB_LOGLEVEL_COUNT];
	};

	extern Logger logInstance;
}

#endif
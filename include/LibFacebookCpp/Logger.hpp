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

#ifndef LIBFACEBOOKCPP_LOGGER_H_
#define LIBFACEBOOKCPP_LOGGER_H_

// This is probably not the best way to do it.
// Leaving it like this for now
// Change it if to we have to once we know more of
// what this logger needs to be able to do
// Also make it so that users can't just create a 
// string themselves to pass in

#define LOG_PARAMS __LINE__, __FILE__
#define GetLog(x) logInstance.GetStream(Logger::x, LOG_PARAMS)

#define GetErrorLog() GetLog(LL_ERROR)
#define GetWarnLog()  GetLog(LL_WARN)
#ifdef DEBUG
#define GetDebugLog() GetLog(LL_DEBUG)
#define GetInfoLog()  GetLog(LL_INFO)
#else
// XXX: Temporarily workaround to get stuff to compile
#define GetDebugLog() GetLog(LL_WARN)
#define GetInfoLog() GetLog(LL_WARN)
#endif // DEBUG

namespace LibFacebookCpp
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

class NoopStream
{
public:
	inline NoopStream& operator << (const std::string &rhs)
	{
		return *this;
	}
};

class Logger
{
public: // public types
	enum LogLevel
	{
		LL_ERROR,
		LL_WARN,
#ifdef DEBUG
		LL_INFO,
		LL_DEBUG,
#endif // DEBUG

		LL_COUNT
	};

public: // public interface
	Logger();
	std::ostream& GetStream(LogLevel level, int lineNumber, const char* file);
	void SetStream(LogLevel level, std::ostream& stream);

private:
	LogStream stream_[LL_COUNT];
};

extern Logger logInstance;

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_LOGGER_H_

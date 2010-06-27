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

#ifndef FACEBOOK_PRECOMPILE_H_
#define FACEBOOK_PRECOMPILE_H_

// XXX: TODO: Static lib

#ifdef LIBFACEBOOKCPP_EXPORTS
#define FACEBOOK_API __declspec(dllexport)
#else // LIBFACEBOOKCPP_EXPORTS
#define FACEBOOK_API __declspec(dllimport)
#endif // LIBFACEBOOKCPP_EXPORTS

#define INTERFACE struct __declspec(novtable)
#define OVERRIDE override

#define _UNUSED(x) ((void)x)

#define ASSERT(x) assert(x); __assume(x); __analysis_assume(x)

#define CASSERT(x) (void)(sizeof(char[2 * !!(x) - 1]))
// XXX: 
#define DASSERT(x) ASSERT(x)

// XXX: TODO: Break on non-arrays
#define NUMELMS(x) sizeof(x) / sizeof(x[0])

// This is probably not the best way to do it.
// Leaving it like this for now
// Change it if to we have to once we know more of
// what this logger needs to be able to do
// Also make it so that users can't just create a 
// string themselves to pass in

#define LOG_PARAMS __LINE__, __FILE__

#define GetErrorLog() logInstance.GetLog(Logger::FB_LOGLEVEL_ERROR, LOG_PARAMS)
#define GetWarnLog()  logInstance.GetLog(Logger::FB_LOGLEVEL_WARN,  LOG_PARAMS)
#define GetInfoLog()  logInstance.GetLog(Logger::FB_LOGLEVEL_INFO,  LOG_PARAMS)
#define GetDebugLog() logInstance.GetLog(Logger::FB_LOGLEVEL_DEBUG, LOG_PARAMS)

#include <json/json.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <map>
#include <list>
#include <sstream>
#include <memory>

using std::tr1::shared_ptr;

#include "Logger.h"

//------------------------------------------
// Let's place this here temporarily
template <typename T>
inline std::string convertToString(T val)
{
	std::stringstream ss;
	ss << val;
	return ss.str();
}

//------------------------------------------
#endif // FACEBOOK_PRECOMPILE_H_
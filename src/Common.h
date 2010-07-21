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

#ifndef LIBFACEBOOKCPP_COMMON_H_
#define LIBFACEBOOKCPP_COMMON_H_

// STL headers
#include <map>
#include <list>
#include <sstream>
#include <memory>
#include <ostream>
#include <set>
#include <ctime>
#include <regex>

// External libraries
#include <json/json.h>
#include <curl/curl.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

// XXX: TODO: Static lib
#ifdef LIBFACEBOOKCPP_EXPORTS
#define LIBFACEBOOKCPP_API __declspec(dllexport)
// Only if we are building libfacebookcpp that we need to worry about enforcing these macros
// Compiler specific defines
#if defined(_MSC_VER)
// Visual C++
#define LIBFACEBOOKCPP_INTERFACE struct __declspec(novtable)
#define LIBFACEBOOKCPP_OVERRIDE override
#define LIBFACEBOOKCPP_ASSERT(x) assert(x); __assume(x); __analysis_assume(x)
#else // defined(_MSC_VER)
// Other compilers
#define LIBFACEBOOKCPP_INTERFACE struct
#define LIBFACEBOOKCPP_OVERRIDE
#define LIBFACEBOOKCPP_ASSERT(x) assert(x)
// XXX:
#error "We need to include shared_ptr"
#endif // defined(_MSC_VER)
#else // LIBFACEBOOKCPP_EXPORTS
#define LIBFACEBOOKCPP_API __declspec(dllimport)
#define LIBFACEBOOKCPP_INTERFACE
#define LIBFACEBOOKCPP_OVERRIDE
#define LIBFACEBOOKCPP_ASSERT(x)
#endif // LIBFACEBOOKCPP_EXPORTS

#define LIBFACEBOOKCPP_CHKARG(arg) if(!(arg)) throw InvalidArgument("Invalid Argument: " #arg);

#define DISALLOW_COPY_AND_ASSIGN(TypeName)   \
	TypeName(const TypeName&);               \
	void operator=(const TypeName&)

namespace LibFacebookCpp
{

using std::tr1::shared_ptr;
using std::tr1::regex;
using std::tr1::cmatch;

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_COMMON_H_

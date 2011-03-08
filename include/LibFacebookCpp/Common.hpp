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
#include <cassert>

// External libraries
// XXX: UGLY!
#include <json/json.h>

// XXX: Some of the CMake stuff includes library (singular, this is bad. It hsould include plurarl!

// Boost headers
#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>

#ifdef _MSC_VER
#define LIBFACEBOOKCPP_OVERRIDE override
#define LIBFACEBOOKCPP_ASSERT(x) assert(x); __assume(x); __analysis_assume(x)
#else
#define LIBFACEBOOKCPP_OVERRIDE
#define LIBFACEBOOKCPP_ASSERT(x) assert(x);
#endif // _MSC_VER

#if defined(LIBFACEBOOKCPP_BUILD_DYNAMIC) && defined(_MSC_VER)
//Dynamic builds
#ifdef LIBFACEBOOKCPP_BUILDING
#define LIBFACEBOOKCPP_API __declspec(dllexport)
#else // LIBFACEBOOKCPP_BUILDING
#define LIBFACEBOOKCPP_API __declspec(dllimport)
#endif // LIBFACEBOOKCPP_BUILDING
#else // defined(LIBFACEBOOKCPP_BUILD_DYNAMIC) && defined(_MSC_VER)
// Static builds
#define LIBFACEBOOKCPP_API
#endif // defined(LIBFACEBOOKCPP_BUILD_DYNAMIC) && defined(_MSC_VER)

#define LIBFACEBOOKCPP_CHKARG(arg) if(!(arg)) throw InvalidArgument("Invalid Argument: " #arg);

#define DISALLOW_COPY_AND_ASSIGN(TypeName)   \
	TypeName(const TypeName&);               \
	void operator=(const TypeName&);

#endif // LIBFACEBOOKCPP_COMMON_H_

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
 *
 */

#ifndef FACEBOOK_COMMON_H_
#define FACEBOOK_COMMON_H_

#define INTERFACE struct __declspec(novtable)
#define OVERRIDE override

#include <cassert>
#include <string>
#include <json/json.h>

// This is probably not the best way to do it.
// Leaving it like this for now
// Change it if to we have to once we know more of
// what this logger needs to be able to do
// Also make it so that users can't just create a 
// string themselves to pass in
#define LogType const char*
#define FB_Warn "Warning: ", __LINE__, __FILE__
#define FB_Error "Error: ", __LINE__, __FILE__ 
#define FB_Message "Message: ", __LINE__ , __FILE__
#define FB_Debug "Debug: ", __LINE__, __FILE__
#define FB_Info "Info: ", __LINE__, __FILE__


#endif // FACEBOOK_COMMON_H_
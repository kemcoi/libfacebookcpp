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

#ifdef _WIN32
// Workaround for Windows retardness
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#endif // _WIN32

#include "Common.h"

// Internal utilities
#include "Logger.h"
#include "Utils.h"

#define goto _USE_OF_GOTO_IS_NOT_ALLOWED_
#define const_cast _USE_OF_CONST_CAST_IS_NOT_ALLOWED_
#define FACEBOOK_CASSERT(x) (void)(sizeof(char[2 * !!(x) - 1]))
// XXX: TODO: Break on non-arrays
#define FACEBOOK_NUMELMS(x) sizeof(x) / sizeof(x[0])

#endif // FACEBOOK_PRECOMPILE_H_
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
#include "Exception.h"

namespace LibFacebookCpp
{

InvalidArgument::InvalidArgument(const std::string& message) : inherited(message)
{
	GetErrorLog() << message;
}

FacebookException::FacebookException(const std::string &type, const std::string &message) : inherited(message)
{
	GetErrorLog() << type << std::endl << message;
}

NotSupportedException::NotSupportedException(const std::string& message) : inherited(message)
{
	GetErrorLog() << message;
}

UnexpectedException::UnexpectedException(const std::string& message) : inherited(message)
{
	GetErrorLog() << message;
}

} // namespace LibFacebookCpp

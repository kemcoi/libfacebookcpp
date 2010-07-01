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

#ifndef FACEBOOK_EXCEPTION_H_
#define FACEBOOK_EXCEPTION_H_

namespace Facebook
{

class FACEBOOK_API InvalidArgument : public std::invalid_argument
{
public:
	typedef std::invalid_argument inherited;
	InvalidArgument(const std::string& message) : inherited(message)
	{
		GetErrorLog() << message;
	}
};

class FACEBOOK_API FacebookException : public std::runtime_error
{
public:
	typedef std::runtime_error inherited;
	FacebookException(const std::string &type, const std::string &message) : inherited(message)
	{
		GetErrorLog() << type << std::endl << message;
	}
};

class FACEBOOK_API NotSupportedException : public std::logic_error
{
public:
	typedef std::logic_error inherited;
	NotSupportedException(const std::string& message) : inherited(message)
	{
		GetErrorLog() << message;
	}
};

class FACEBOOK_API UnexpectedException : public std::logic_error
{
public:
	typedef std::logic_error inherited;
	UnexpectedException(const std::string& message) : inherited(message)
	{
		GetErrorLog() << message;
	}
};

} // namespace Facebook

#endif // FACEBOOK_EXCEPTION_H_

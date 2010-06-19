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

#ifndef FACEBOOK_HTTPREQUEST_H_
#define FACEBOOK_HTTPREQUEST_H_

#include <list>

namespace Facebook
{
	struct Uri
	{
		typedef std::list<std::pair<std::string, std::string>> QueryParamList;

		std::string base_uri;
		QueryParamList query_params;

		std::string GetUri() const;
	};

	class HttpRequest
	{
	public: // public types
		typedef std::list<std::pair<std::string, std::string>> QueryParamList;

	public: // public interface
		std::auto_ptr<Json::Value> GetResponse(const Uri& uri);

	private: // member variables
	};
}

#endif // FACEBOOK_HTTPREQUEST_H_

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

#include "HTTPRequest.h"
#include "Exception.h"

namespace Facebook
{

std::string Uri::GetUri() const
{
	if(base_uri.empty())
		throw InvalidArgument("base_uri");

	std::ostringstream oss;

	oss << base_uri;

	if(query_params.size() > 0)
	{
		oss << "?";

		// Due to the check above, we must have at least one element

		QueryParamMap::const_iterator it = query_params.begin();

		oss << curlpp::escape(it->first) << "=" << curlpp::escape(it->second);
		++it;

		while(it != query_params.end())
		{
			oss << '&';
			oss << curlpp::escape(it->first) << "=" << curlpp::escape(it->second);
			++it;
		}
	}

	return oss.str();
}

namespace HttpUtils
{

void DecomposeUri(const std::string& str, Uri& uri)
{
	uri.Clear();

	std::string::size_type lastPos = str.find('?');

	if(std::string::npos == lastPos)
	{
		uri.base_uri = str;
	}
	else
	{
		uri.base_uri = str.substr(0, lastPos);

		// XXX: This is an inefficient algorithm. Need to speed it up

		std::list<std::string> list;

		++lastPos;
		std::string::size_type pos = str.find_first_of("&=", lastPos);

		while (std::string::npos != pos || std::string::npos != lastPos)
		{
			list.push_back(str.substr(lastPos, pos - lastPos));
			lastPos = str.find_first_not_of("&=", pos);
			pos = str.find_first_of("&=", lastPos);
		}

		assert(list.size() % 2 == 0);

		for(std::list<std::string>::const_iterator it = list.begin(); it != list.end();)
		{
			std::string str1 = *it++;
			std::string str2 = *it++;
			uri.query_params.insert(std::pair<std::string, std::string>(curlpp::unescape(str1), curlpp::unescape(str2)));
		}
	}
}

} // namespace HttpUtils

void HttpRequest::GetResponse(const Uri& uri, Json::Value &value)
{
	// First build the final url

	curlpp::Easy curl;
	GetDebugLog() << uri.GetUri();
	curl.setOpt(curlpp::options::Url(uri.GetUri()));
	// TODO: We shouldn't be disabling this. Instead, implementing our own Ctx
	curl.setOpt(curlpp::options::SslVerifyPeer(false));

	std::stringstream oss;

	// This performs the request and dumps the output to the stringstream
	oss << curl;

	Json::Reader reader;
	reader.parse(oss, value);
}

void HttpRequest::GetUri(Uri *uri) const
{
	FACEBOOK_ASSERT(uri);

	uri->query_params.insert(std::pair<std::string, std::string>("access_token", access_token_));
}

} // namespace Facebook

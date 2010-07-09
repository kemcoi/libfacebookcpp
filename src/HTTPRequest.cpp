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
#include "RequestBlob.h"

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

		FACEBOOK_ASSERT(list.size() % 2 == 0);

		for(std::list<std::string>::const_iterator it = list.begin(); it != list.end();)
		{
			std::string str1 = *it++;
			std::string str2 = *it++;
			uri.query_params.insert(std::pair<std::string, std::string>(curlpp::unescape(str1), curlpp::unescape(str2)));
		}
	}
}

} // namespace HttpUtils

size_t HttpRequest::DebugFunction(curl_infotype /* type */, char * /* data */, size_t /* size */)
{
	// Fix for issue #28: Only print to the debug log if we are text-based data
	//if(CURLINFO_TEXT == type)
	//	GetDebugLog().write(data, size);
	return 0;
}

size_t HttpRequest::HeaderFunction(char *data, size_t size, size_t nmemb)
{
	FACEBOOK_ASSERT(blob_);

	cmatch result;
	// TODO: This is inefficient, but making it static makes us leak memory. We need a global ->Init(); call
	// which initializes this regex, etc.
	regex rx("(\\s)*([^:]+)(\\s)*:(\\s)*(.+)(\\s)*");

	if(regex_search((const char*)data, (const char*)data + size * nmemb, result, rx))
	{
		// regex really only allows us to get a .str() out of the matches
		std::string header = result[2].str();
		if(strcmpi(header.c_str(), "Content-Type") == 0)
		{
			blob_->SetContentType(result[5].str());
			GetDebugLog() << "Got content-type of " << result[5] << std::endl;
		}
		else if(strcmpi(header.c_str(), "Content-Length") == 0)
		{
			GetDebugLog() << "Got content-length of " << result[5] << std::endl;
		}
	}

	return size * nmemb;
}

size_t HttpRequest::WriteFunction(char *data, size_t size, size_t nmemb)
{
	// TODO: This is a little inefficient. We should be allocating in larger chunks and reusing
	// the chunks

	FACEBOOK_ASSERT(blob_);
	FACEBOOK_ASSERT(data);

	size_t old_length = blob_->GetLength();
	blob_->Realloc(old_length + size * nmemb);
	memcpy((char*)blob_->GetData() + old_length, data, size * nmemb);
	return size * nmemb;
}

void HttpRequest::GetResponse(const Uri& uri, RequestBlob *blob)
{
	FACEBOOK_ASSERT(blob);
	FACEBOOK_ASSERT(!blob_); // This object isn't thread-safe!

	blob_ = blob;

	// GetDebugLog() << uri.GetUri();
	curl_.setOpt(curlpp::options::Url(uri.GetUri()));
	curl_.perform();

	blob_ = NULL;
}

void HttpRequest::GetResponse(const Uri& uri, Json::Value *value)
{
	FACEBOOK_ASSERT(value);

	RequestBlob blob;
	GetResponse(uri, &blob);

	Json::Reader reader;
	reader.parse((char*)blob.GetData(), (char*)blob.GetData() + blob.GetLength(), *value);
}

void HttpRequest::GetUri(Uri *uri) const
{
	FACEBOOK_ASSERT(uri);

	uri->query_params.insert(std::pair<std::string, std::string>("access_token", access_token_));
}

HttpRequest::HttpRequest(const std::string &access_token) : access_token_(access_token), blob_(NULL)
{
	curl_.setOpt(curlpp::Options::Verbose(true));
	curl_.setOpt(curlpp::options::DebugFunction(curlpp::types::DebugFunctionFunctor(this, &HttpRequest::DebugFunction)));
	curl_.setOpt(curlpp::Options::WriteFunction(curlpp::types::WriteFunctionFunctor(this, &HttpRequest::WriteFunction)));
	curl_.setOpt(curlpp::Options::HeaderFunction(curlpp::types::WriteFunctionFunctor(this, &HttpRequest::HeaderFunction)));
	curl_.setOpt(curlpp::Options::FollowLocation(true));
	// TODO: We shouldn't be disabling this. Instead, implementing our own Ctx
	curl_.setOpt(curlpp::options::SslVerifyPeer(false));
}
} // namespace Facebook

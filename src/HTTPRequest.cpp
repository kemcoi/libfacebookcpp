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
#include "ResponseBlob.h"

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

	if(anchor.size() > 0)
	{
		oss << "#" << anchor;
	}

	return oss.str();
}

Uri::Uri(const std::string &str)
{
	cmatch uriResult;
	// TODO: This is inefficient but I don't want to declare static objects
	regex uriRx("^([^\\?#])+\\??([^#]+)?#?(.+)?$");

	if(!regex_search(str.c_str(), uriResult, uriRx))
		throw UnexpectedException("!regex_search");

	base_uri = uriResult[1].str();
	anchor = uriResult[3].str();

	// For decomposing query params, we have to run a second regex, since the first regex is obfuscated as enough
	cmatch queryParamsResult;
	regex queryParamsRx("[^=&]+=[^&]+");

	if(!regex_search(str.c_str(), queryParamsResult, queryParamsRx))
		throw UnexpectedException("!regex_search");

	FACEBOOK_ASSERT(queryParamsResult.size() % 2 == 0);

	for(cmatch::const_iterator it = queryParamsResult.begin(); it != queryParamsResult.end(); )
	{
		std::pair<std::string, std::string> pair;
		pair.first = *(it++);
		pair.second = *(it++);

		query_params.insert(pair);
	}
}

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
	regex rx("^(\\s)*([^:]+)(\\s)*:(\\s)*(.+)(\\s)*$");

	if(regex_search((const char*)data, (const char*)data + size * nmemb, result, rx))
	{
		if(result[2].matched && result[5].matched)
		{
			std::string header = result[2].str();
			if(strcmpi(header.c_str(), "Content-Type") == 0)
			{
				blob_->SetContentType(result[5].str());
				GetDebugLog() << "Got content-type of " << result[5] << std::endl;
			}
			else if(strcmpi(header.c_str(), "Content-Length") == 0)
			{
				blob_->Realloc(fromString<size_t>(result[5].str()));
				GetDebugLog() << "Got content-length of " << result[5] << std::endl;
			}
		}
	}

	return size * nmemb;
}

size_t HttpRequest::WriteFunction(char *data, size_t size, size_t nmemb)
{
	FACEBOOK_ASSERT(blob_);
	FACEBOOK_ASSERT(data);

	if(blobDataSize_ + size * nmemb > blob_->GetLength())
	{
		// Extend the buffer by 4k
		static const size_t s_bufferExtension = 4096;
		blob_->Realloc(blobDataSize_ + size * nmemb + s_bufferExtension);
	}

	memcpy((char*)blob_->GetData() + blobDataSize_, data, size * nmemb);
	blobDataSize_ += size * nmemb;
	return size * nmemb;
}

void HttpRequest::GetResponse(const Uri& uri, ResponseBlob *blob)
{
	FACEBOOK_ASSERT(blob);
	FACEBOOK_ASSERT(!blob_); // This object isn't thread-safe!
	FACEBOOK_ASSERT(blobDataSize_ == 0);

	blob_ = blob;
	blobDataSize_ = 0;

	// GetDebugLog() << uri.GetUri();
	curl_.setOpt(curlpp::options::Url(uri.GetUri()));
	curl_.perform();

	blob_->Realloc(blobDataSize_);

	blob_ = NULL;
	blobDataSize_ = 0;
}

void HttpRequest::GetResponse(const Uri& uri, Json::Value *value)
{
	FACEBOOK_ASSERT(value);

	ResponseBlob blob;
	GetResponse(uri, &blob);

	Json::Reader reader;
	reader.parse((char*)blob.GetData(), (char*)blob.GetData() + blob.GetLength(), *value);
}

void HttpRequest::GetUri(Uri *uri) const
{
	FACEBOOK_ASSERT(uri);

	uri->query_params.insert(std::pair<std::string, std::string>("access_token", access_token_));
}

HttpRequest::HttpRequest(const std::string &access_token) : access_token_(access_token), blob_(NULL), blobDataSize_(0)
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

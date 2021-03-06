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

#include "precompile.hpp"

#include "HTTPRequest.hpp"
#include "Exception.hpp"
#include "ResponseBlob.hpp"

namespace LibFacebookCpp
{

std::string Uri::GetUri() const
{
	if(base_uri.empty())
		throw InvalidArgument("base_uri");

	StringBuilder builder;

	builder << base_uri;

	if(query_params.size() > 0)
	{
		builder << "?";

		// Due to the check above, we must have at least one element

		QueryParamMap::const_iterator it = query_params.begin();

		builder << HttpUtils::Escape(it->first) << "=" << HttpUtils::Escape(it->second);
		++it;

		while(it != query_params.end())
		{
			builder << '&';
			builder << HttpUtils::Escape(it->first) << "=" << HttpUtils::Escape(it->second);
			++it;
		}
	}

	return builder;
}

namespace HttpUtils
{

template<class T>
static void CurlEasySetOpt(CURL *curl, CURLoption opt, T val);

template<>
static void CurlEasySetOpt(CURL *curl, CURLoption opt, long val)
{
	CURLcode result = curl_easy_setopt(curl, opt, val);
	if(CURLE_OK != result)
		throw CurlException("Unable to set opt on CURL");
}

template<>
static void CurlEasySetOpt(CURL *curl, CURLoption opt, const char *val)
{
	CURLcode result = curl_easy_setopt(curl, opt, val);
	if(CURLE_OK != result)
		throw CurlException("Unable to set opt on CURL");
}

template<>
static void CurlEasySetOpt(CURL *curl, CURLoption opt, void *val)
{
	CURLcode result = curl_easy_setopt(curl, opt, val);
	if(CURLE_OK != result)
		throw CurlException("Unable to set opt on CURL");
}

static void CurlEasyPerform(CURL *curl)
{
	CURLcode result = curl_easy_perform(curl);
	if(CURLE_OK != result)
		throw CurlException("Failed to perform CURL operation");
}

void DecomposeUri(const std::string& str, Uri *uri)
{
	LIBFACEBOOKCPP_ASSERT(uri);

	uri->Clear();

	std::string::size_type lastPos = str.find('?');

	if(std::string::npos == lastPos)
	{
		uri->base_uri = str;
	}
	else
	{
		uri->base_uri = str.substr(0, lastPos);

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

		LIBFACEBOOKCPP_ASSERT(list.size() % 2 == 0);

		for(std::list<std::string>::const_iterator it = list.begin(); it != list.end();)
		{
			std::string str1 = *it++;
			std::string str2 = *it++;

			uri->query_params.insert(std::pair<std::string, std::string>(HttpUtils::Unescape(str1), HttpUtils::Unescape(str2)));
		}
	}
}

std::string Escape(const std::string& str)
{
	char *escaped = curl_easy_escape(NULL, str.c_str(), str.length());

	if(!escaped)
		throw CurlException("CURL failed to escape string");

	std::string escapedStr(escaped);
	curl_free(escaped);
	return escapedStr;
}

std::string Unescape(const std::string& str)
{
	char *unescaped = curl_easy_unescape(NULL, str.c_str(), str.length(), NULL);

	if(!unescaped)
		throw CurlException("CURL failed to unescape string");

	std::string unescapedStr(unescaped);
	curl_free(unescaped);
	return unescapedStr;
}

} // namespace HttpUtils

#ifdef DEBUG
size_t HttpRequest::DebugFunction(curl_infotype type, char *data, size_t size, void *userdata)
{
	// Issue #28: Only print to the debug log if we are text-based data. If not, we'll start printing special control codes
	// which include the alert code
	if(CURLINFO_TEXT == type)
		GetDebugLog().write(data, size);
	return 0;
}
#endif // DEBUG

size_t HttpRequest::HeaderFunction(char *data, size_t size, size_t nmemb, void *userdata)
{
	LIBFACEBOOKCPP_ASSERT(userdata);

	HttpRequest *request = static_cast<HttpRequest*>(userdata);
	LIBFACEBOOKCPP_ASSERT(request->blob_);

	// This would typically be done by a regex in _any_ language, however... for pure efficiency reasons, do this parsing by hand here
	// Note: In order to make out lives _a little_ easier, we do an initial string copy. This really does help us a lot in
	// preventing us from re-writing half of C's string library

	std::string header(data, size * nmemb);
	std::string::size_type found = header.find(':');

	if(std::string::npos != found)
	{
		std::string headerKey = header.substr(0, found);

		if(strcmpi(headerKey.c_str(), "Content-Type") == 0)
		{
			std::string::size_type startPos = header.find_first_not_of(" ", found + 1);
			std::string::size_type endPos = header.find_last_not_of(" \r\n");
			std::string headerData = header.substr(startPos, endPos - startPos - 1);

			request->blob_->SetContentType(headerData);
			GetDebugLog() << "Got content-type of " << headerData << std::endl;
		}
		else if(strcmpi(headerKey.c_str(), "Content-Length") == 0)
		{
			std::string::size_type startPos = header.find_first_not_of(" ", found + 1);
			std::string::size_type endPos = header.find_last_not_of(" \r\n");
			std::string headerData = header.substr(startPos, endPos - startPos - 1);

			request->blob_->Realloc(fromString<size_t>(headerData));
			GetDebugLog() << "Got content-length of " << headerData << std::endl;
		}
	}

	return size * nmemb;
}

size_t HttpRequest::WriteFunction(char *data, size_t size, size_t nmemb, void *userdata)
{
	LIBFACEBOOKCPP_ASSERT(userdata);

	HttpRequest *request = static_cast<HttpRequest*>(userdata);
	LIBFACEBOOKCPP_ASSERT(request->blob_);

	LIBFACEBOOKCPP_ASSERT(data);

	if(request->blobSize_ + size * nmemb > request->blob_->GetLength())
	{
		// Extend the buffer by 4k
		static const size_t s_bufferExtension = 4096;
		request->blob_->Realloc(request->blobSize_ + size * nmemb + s_bufferExtension);
	}

	memcpy((char*)request->blob_->GetData() + request->blobSize_, data, size * nmemb);
	request->blobSize_ += size * nmemb;
	return size * nmemb;
}

void HttpRequest::PostResponse(const Uri &uri, ResponseBlob *blob)
{
	LIBFACEBOOKCPP_ASSERT(uri.IsValid());
	LIBFACEBOOKCPP_ASSERT(blob);
	LIBFACEBOOKCPP_ASSERT(!blob_); // This object isn't thread-safe, and neither is this check!
	LIBFACEBOOKCPP_ASSERT(blobSize_ == 0);

	// XXX: Fix this!
//	GetDebugLog() << uri;

	blob_ = blob;
	blobSize_ = 0;

	// The C++ standard garuntees that the const char * returned by the c_str() is valid until any subsequent calls
	// to the string. Hence, in this code, after the c_str(), we do not do anything with the uri.base_uri
	HttpUtils::CurlEasySetOpt<const char*>(curl_, CURLOPT_URL, uri.base_uri.c_str());
	HttpUtils::CurlEasySetOpt<long>(curl_, CURLOPT_HTTPPOST, 1);

	// XXX: Mangle params together here!
	std::string params;

	// Same explanation for the non-crashing behavior as the one stated for the uri.base_uri up-above
	HttpUtils::CurlEasySetOpt<const char*>(curl_, CURLOPT_POSTFIELDS, params.c_str());

	HttpUtils::CurlEasyPerform(curl_);

	blob_->Realloc(blobSize_);

	blob_ = NULL;
	blobSize_ = 0;
}

void HttpRequest::GetResponse(const std::string& uri, ResponseBlob *blob)
{
	LIBFACEBOOKCPP_ASSERT(blob);
	LIBFACEBOOKCPP_ASSERT(!blob_); // This object isn't thread-safe!
	LIBFACEBOOKCPP_ASSERT(blobSize_ == 0);

	GetDebugLog() << uri;

	blob_ = blob;
	blobSize_ = 0;

	HttpUtils::CurlEasySetOpt<long>(curl_, CURLOPT_HTTPGET, 1);
	HttpUtils::CurlEasySetOpt<const char*>(curl_, CURLOPT_URL, uri.c_str());
	HttpUtils::CurlEasyPerform(curl_);

	blob_->Realloc(blobSize_);

	blob_ = NULL;
	blobSize_ = 0;
}

// XXX: Fix this!
//void HttpRequest::PostResponse(const std::string &uri, Json::Value *value)
//{
//	LIBFACEBOOKCPP_ASSERT(value);
//
//	ResponseBlob blob;
//	PostResponse(uri, &blob);
//
//	Json::Reader reader;
//	reader.parse((char*)blob.GetData(), (char*)blob.GetData() + blob.GetLength(), *value);
//}

void HttpRequest::GetResponse(const std::string& uri, Json::Value *value)
{
	LIBFACEBOOKCPP_CHKARG(value);

	ResponseBlob blob;
	GetResponse(uri, &blob);

	Json::Reader reader;
	reader.parse((char*)blob.GetData(), (char*)blob.GetData() + blob.GetLength(), *value);
}

void HttpRequest::GetUri(Uri *uri) const
{
	LIBFACEBOOKCPP_ASSERT(uri);

	uri->query_params.insert(std::pair<std::string, std::string>("access_token", access_token_));
}

HttpRequest::HttpRequest(const std::string &access_token) : curl_(NULL), blob_(NULL), blobSize_(0), access_token_(access_token)
{
	curl_ = curl_easy_init();

	if(!curl_)
		throw CurlException("Unable to create a CURL handle");

	// XXX: This should be fixed and be set as a dynamic value!
#ifdef DEBUG
	HttpUtils::CurlEasySetOpt<long>(curl_, CURLOPT_VERBOSE, 1);
	HttpUtils::CurlEasySetOpt<void*>(curl_, CURLOPT_DEBUGFUNCTION, &HttpRequest::DebugFunction);
	HttpUtils::CurlEasySetOpt<void*>(curl_, CURLOPT_DEBUGDATA, this);
#endif // DEBUG

	HttpUtils::CurlEasySetOpt<void*>(curl_, CURLOPT_WRITEFUNCTION, &HttpRequest::WriteFunction);
	HttpUtils::CurlEasySetOpt<void*>(curl_, CURLOPT_WRITEDATA, this);

	HttpUtils::CurlEasySetOpt<void*>(curl_, CURLOPT_HEADERFUNCTION, &HttpRequest::HeaderFunction);
	HttpUtils::CurlEasySetOpt<void*>(curl_, CURLOPT_HEADERDATA, this);

	HttpUtils::CurlEasySetOpt<long>(curl_, CURLOPT_FOLLOWLOCATION, 1);

	//// TODO: We shouldn't be disabling this. Instead, implementing our own Ctx
	HttpUtils::CurlEasySetOpt<long>(curl_, CURLOPT_SSL_VERIFYPEER, 0);
}

} // namespace LibFacebookCpp

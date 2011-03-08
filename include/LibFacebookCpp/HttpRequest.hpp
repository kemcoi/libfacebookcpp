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

#ifndef LIBFACEBOOKCPP_HTTP_REQUEST_H_
#define LIBFACEBOOKCPP_HTTP_REQUEST_H_

#include <curl/curl.h>

namespace LibFacebookCpp
{

struct Uri
{
	typedef std::map<std::string, std::string> QueryParamMap;

	std::string base_uri;
	QueryParamMap query_params;

	// A URI is valid (assuming correct base_uri), if a base_uri is present
	bool IsValid() const { return !base_uri.empty(); }
	std::string GetUri() const;
	void Clear() { base_uri.clear(); query_params.clear(); }
};

namespace HttpUtils
{

void DecomposeUri(const std::string& str, Uri *uri);
std::string Escape(const std::string& str);
std::string Unescape(const std::string& str);

} // namespace LibFacebookCpp

class ResponseBlob;

class HttpRequest
{
private: // private ctor
	HttpRequest(const std::string &access_token);

private: // private helper functions
	static size_t HeaderFunction(char *data, size_t size, size_t nmemb, void *userdata);
	static size_t WriteFunction(char *data, size_t size, size_t nmemb, void *userdata);
	static size_t DebugFunction(curl_infotype type, char *data, size_t size, void *userdata);

public: // public interface
	void PostResponse(const std::string &uri, Json::Value *value);
	void PostResponse(const Uri &uri, ResponseBlob *blob);

	void GetResponse(const std::string& uri, ResponseBlob *blob);
	void GetResponse(const std::string& uri, Json::Value *value);
	void GetUri(Uri *uri) const;

private: // member variables
	CURL *curl_;
	ResponseBlob *blob_;
	size_t blobSize_;
	std::string access_token_;

	friend class Session;
};

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_HTTP_REQUEST_H_

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

#ifndef FACEBOOK_HTTPREQUEST_H_
#define FACEBOOK_HTTPREQUEST_H_

namespace Facebook
{

struct Uri
{
	typedef std::map<std::string, std::string> QueryParamMap;

	std::string base_uri;
	QueryParamMap query_params;

	std::string GetUri() const;
	void Clear() { base_uri.clear(); query_params.clear(); }
};

namespace HttpUtils
{

void DecomposeUri(const std::string& str, Uri& uri);

} // namespace Facebook

class Blob;

class HttpRequest
{
private: // private ctor
	HttpRequest(const std::string &access_token) : access_token_(access_token) { }

private: // private helper classes
	class HttpRequestBlob
	{
	public: // ctor and ~()
		HttpRequestBlob(Blob *blob) : blob_(blob) { }

		size_t WriteFunction(char *data, size_t size, size_t nmemb);

	private:
		Blob *blob_;
	};

private: // private helper functions
	int CurlDebugFunction(int, char *data, size_t size);

public: // public interface
	void HttpRequest::GetResponse(const Uri& uri, Blob *blob);
	void GetResponse(const Uri& uri, Json::Value *value);
	void GetUri(Uri *uri) const;

private: // member variables
	std::string access_token_;

	friend class Session;
};

} // namespace Facebook

#endif // FACEBOOK_HTTPREQUEST_H_

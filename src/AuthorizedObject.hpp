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

#ifndef LIBFACEBOOKCPP_AUTHORIZED_OBJECT_H_
#define LIBFACEBOOKCPP_AUTHORIZED_OBJECT_H_

#include "HttpRequest.hpp"

namespace LibFacebookCpp
{

class HttpRequest;
class ResponseBlob;
struct PagingInfo;
struct Uri;

template<class FBType>
class List;

enum LIBFACEBOOKCPP_API PictureSize
{
	PS_SQUARE,
	PS_SMALL,
	PS_LARGE,

	PS_COUNT
};

class AuthorizedObject
{
protected:
	void Init(const AuthorizedObject &obj);
	void Init(const shared_ptr<HttpRequest>& request);

private:
	void Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);
	virtual void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) = 0;

protected: // interface
	AuthorizedObject() { }

	// XXX: Get rid of the "_". They are reserved for internal C++ library usage only!

	void _GetPictureConnection(const std::string &id, PictureSize size, ResponseBlob *blob) const;

	// XXX: Find class T and replace with TType
	// XXX: Find a better name for _PostConnection
	// XXX: Figure out the params required for this
	// XXX: typedef std::map<>
	// XXX: Re-use QueryMapParam
	template<class TType>
	void _PostConnection(const std::string &url, const std::map<std::string, std::string> &params, TType *t)
	{
		Uri uri;
		request_->GetUri(&uri);

		uri.base_uri = url;
		uri.query_params.insert(params.begin(), params.end());

		// XXX: Why doesn't GetResponse take a uri directly?

		Json::Value value;
		request_->PostResponse(uri, &value);

		t->Deserialize(*this, value);
	}

	template<class TType>
	void _GetConnection(const std::string &id, const char *page, TType *t) const
	{
		LIBFACEBOOKCPP_ASSERT(page);
		LIBFACEBOOKCPP_CHKARG(t);

		// XXX: Need to check if we are .Valid() or not

		Uri uri;
		request_->GetUri(&uri);

		uri.base_uri = StringBuilder() << "https://graph.facebook.com/" << HttpUtils::Escape(id) << "/" << HttpUtils::Unescape(page);

		Json::Value value;
		request_->GetResponse(uri.GetUri(), &value);

		t->Deserialize(*this, value);
	}

	template<class TType>
	void _GetConnection(const std::string& uri, List<TType> *list) const
	{
		LIBFACEBOOKCPP_CHKARG(list);

		Json::Value value;
		request_->GetResponse(uri, &value);
		list->Deserialize(*this, value);
	}

	template<class TType>
	void _GetConnection(const std::string &id, const char *page, const PagingInfo *paging, List<TType> *list) const
	{
		LIBFACEBOOKCPP_ASSERT(page);
		LIBFACEBOOKCPP_CHKARG(list);

		Uri uri;
		request_->GetUri(&uri);

		uri.base_uri = StringBuilder() << "https://graph.facebook.com/" << HttpUtils::Escape(id) << "/" << HttpUtils::Escape(page);

		if(paging)
			paging->GetUri(&uri);

		_GetConnection(uri.GetUri(), list);
	}

private:
	shared_ptr<HttpRequest> request_;

	friend class Deserializer;
};

} // namespace LibFacebookCpp

// XXX: Hack!
#include "List.hpp"

#endif // LIBFACEBOOKCPP_AUTHORIZED_OBJECT_H_
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

#ifndef LIBFACEBOOKCPP_AUTHORIZED_OBJECT_H_
#define LIBFACEBOOKCPP_AUTHORIZED_OBJECT_H_

#include "HttpRequest.h"
// XXX: Remove the FB prefix to everything

namespace LibFacebookCpp
{

class ResponseBlob;
class HttpRequest;
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

protected: // interface
	AuthorizedObject() { }

	virtual void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) = 0;

	template<class TType>
	void _GetConnection(const std::string &id, const char *page, TType *t) const
	{
		LIBFACEBOOKCPP_ASSERT(page);
		LIBFACEBOOKCPP_ASSERT(t);

		Uri uri;
		request_->GetUri(&uri);

		std::ostringstream base_uri;
		base_uri << "https://graph.facebook.com/" << curlpp::escape(id) << "/" << curlpp::escape(page);
		uri.base_uri = base_uri.str();

		Json::Value value;
		request_->GetResponse(uri.GetUri(), &value);

		t->Deserialize(*this, value);
	}

	void _GetPictureConnection(const std::string &id, PictureSize size, ResponseBlob *blob) const;

	template<class TType>
	void _GetConnection(const std::string &id, const char *page, const PagingInfo *paging, List<TType> *list) const
	{
		LIBFACEBOOKCPP_ASSERT(page);
		LIBFACEBOOKCPP_ASSERT(list);

		Uri uri;
		request_->GetUri(&uri);

		std::ostringstream base_uri;
		base_uri << "https://graph.facebook.com/" << curlpp::escape(id) << "/" << curlpp::escape(page);
		uri.base_uri = base_uri.str();

		if(paging)
			paging->GetUri(&uri);

		Json::Value value;
		request_->GetResponse(uri.GetUri(), &value);

		list->Deserialize(*this, value);
	}

	/*
	template<class TType>
	void _GetConnection(const std::string &id, const char *page, std::list<TType> *list, const PagingInfo *paging) const
	{
		LIBFACEBOOKCPP_ASSERT(page);
		LIBFACEBOOKCPP_ASSERT(list);

		Uri uri;
		request_->GetUri(&uri);

		std::ostringstream base_uri;
		base_uri << "https://graph.facebook.com/" << curlpp::escape(id) << "/" << curlpp::escape(page);
		uri.base_uri = base_uri.str();

		if(paging)
			paging->GetUri(&uri);

		Json::Value value;
		request_->GetResponse(uri, &value);

		Deserializer deserializer(*this, value);
		deserializer.Deserialize("data", true, list);
	}
	*/

private:
	shared_ptr<HttpRequest> request_;

	friend class Deserializer;
};

} // namespace LibFacebookCpp

// XXX: Hack!
#include "List.h"

#endif // LIBFACEBOOKCPP_AUTHORIZED_OBJECT_H_
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

#ifndef FACEBOOK_AUTHORIZED_OBJECT_H_
#define FACEBOOK_AUTHORIZED_OBJECT_H_

#include "HttpRequest.h"

namespace Facebook
{

class RequestBlob;
class HttpRequest;
struct PagingInfo;
struct Uri;

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
	void GetConnection(const std::string &base_uri, TType *t) const
	{
		FACEBOOK_ASSERT(t);

		Uri uri;
		request_->GetUri(&uri);

		uri.base_uri = base_uri;

		Json::Value value;
		request_->GetResponse(uri, &value);

		t->Deserialize(*this, value);
	}

	template<>
	void GetConnection(const std::string &base_uri, RequestBlob *blob) const
	{
		FACEBOOK_ASSERT(blob);

		Uri uri;
		request_->GetUri(&uri);

		uri.base_uri = base_uri;
		
		request_->GetResponse(uri, blob);
	}

	template<class TType>
	void GetConnection(const std::string &base_uri, std::list<TType> *list, const PagingInfo *paging) const
	{
		FACEBOOK_ASSERT(list);

		Uri uri;
		request_->GetUri(&uri);

		uri.base_uri = base_uri;

		if(paging)
			paging->GetUri(&uri);

		Json::Value value;
		request_->GetResponse(uri, &value);

		Deserializer deserializer(*this, value);
		deserializer.Deserialize("data", true, list);
	}

private:
	// XXX: This makes us thread-safe up to the Session level
	shared_ptr<HttpRequest> request_;

	friend class Deserializer;
};

} // namespace Facebook

#endif // FACEBOOK_AUTHORIZED_OBJECT_H_
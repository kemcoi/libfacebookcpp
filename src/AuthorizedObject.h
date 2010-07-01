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

namespace Facebook
{

class HttpRequest;
struct PagingInfo;
struct Uri;

class AuthorizedObject
{
public:
	void Init(const AuthorizedObject &obj);
	void Init(const shared_ptr<HttpRequest>& request);
	// TODO: PURE it without creating a havoc
	virtual void Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

protected: // interface
	AuthorizedObject() { }

	template<class TType>
	void GetConnection(const std::string &base_uri, std::list<TType> *list, const PagingInfo *paging) const
	{
		FACEBOOK_ASSERT(list);

		Uri uri;
		GetHttpRequest()->GetUri(&uri);

		uri.base_uri = base_uri;

		if(paging)
			paging->GetUri(&uri);

		Json::Value value;
		GetHttpRequest()->GetResponse(uri, &value);

		Deserializer deserializer(*this, value);
		deserializer.Deserialize("data", true, list);
	}

	const shared_ptr<HttpRequest>& GetHttpRequest() const { return request_; }
	shared_ptr<HttpRequest>& GetHttpRequest() { return request_; }

private:
	// XXX: This makes us thread-safe up to the Session level
	shared_ptr<HttpRequest> request_;

	friend class Deserializer;
};

} // namespace Facebook

#endif // FACEBOOK_AUTHORIZED_OBJECT_H_
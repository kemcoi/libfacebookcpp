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

	class AuthorizedObject
	{
	public:
		// TODO: PURE it without creating a havoc
		virtual void Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) { _UNUSED(parent_obj); _UNUSED(json); } // = 0;

	protected: // interface
		AuthorizedObject() { }

		const shared_ptr<HttpRequest>& GetHttpRequest() const { return request_; }
		shared_ptr<HttpRequest>& GetHttpRequest() { return request_; }

	private:
		// XXX: This makes us thread-safe up to the Session level
		shared_ptr<HttpRequest> request_;

		friend class Deserializer;
		friend class Session;
	};
}

#endif // FACEBOOK_AUTHORIZED_OBJECT_H_
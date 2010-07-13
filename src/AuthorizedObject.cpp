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
#include "AuthorizedObject.h"

namespace LibFacebookCpp
{

void AuthorizedObject::Init(const shared_ptr<HttpRequest>& request)
{
	request_ = request;
}

void AuthorizedObject::Init(const AuthorizedObject &obj)
{
	request_ = obj.request_;
}

void AuthorizedObject::Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	_Deserialize(parent_obj, json);
}

void AuthorizedObject::_GetPictureConnection(const std::string &id, PictureSize size, ResponseBlob *blob) const
{
	LIBFACEBOOKCPP_ASSERT(size >= FPS_SQUARE && size <= FPS_LARGE);
	LIBFACEBOOKCPP_ASSERT(blob);

	FACEBOOK_CASSERT(FPS_SQUARE == 0 && FPS_LARGE == FPS_COUNT - 1);

	Uri uri;
	request_->GetUri(&uri);

	std::ostringstream base_uri;
	base_uri << "https://graph.facebook.com/" << curlpp::escape(id) << "/picture";
	uri.base_uri = base_uri.str();

	static const char *s_sizeType[] = {
		{ "square"}, // FPS_SQUARE
		{ "small" }, // FPS_SMALL
		{ "large" }, // FPS_LARGE
	};

	FACEBOOK_CASSERT(FACEBOOK_NUMELMS(s_sizeType) == FPS_COUNT);

	uri.query_params["type"] = s_sizeType[size];

	request_->GetResponse(uri, blob);
}

} // namespace LibFacebookCpp

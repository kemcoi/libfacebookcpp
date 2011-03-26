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
#include "Link.hpp"
#include "Deserializer.hpp"
#include "Friend.hpp"
#include "Comment.hpp"
#include "PagingInfo.hpp"

namespace LibFacebookCpp
{

void Link::GetComments(List<Comment> *list, const PagingInfo *paging /*= NULL*/) const
{
	_GetConnection(id_, "comments", paging, list);
}

void Link::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer d(parent_obj, this, json);

	d.Deserialize("id", true, &id_);
	d.Deserialize("from", false, &from_);
	d.Deserialize("link", false, &link_);
	d.Deserialize("name", false, &name_);
	d.Deserialize("caption", false, &caption_);
	d.Deserialize("description", false, &description_);
	d.Deserialize("message", false, &message_);
	d.Deserialize("updated_time", false, &updated_time_);
}

} // namespace LibFacebookCpp
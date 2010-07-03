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
#include "Post.h"
#include "Deserializer.h"
#include "PagingInfo.h"
#include "Comment.h"

namespace Facebook
{

void Post::GetComments(std::list<Comment> *list, const PagingInfo *paging /*= NULL*/)
{
	GetConnection("https://graph.facebook.com/" + id_ + "/comments", list, paging);
}

void Post::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer d(parent_obj, this, json);

	d.Deserialize("id", true, &id_);
	d.Deserialize("from", false, &from_);
	d.Deserialize("to", false, &to_);
	d.Deserialize("message", false, &message_);
	d.Deserialize("picture", false, &picture_);
	d.Deserialize("link", false, &link_);
	d.Deserialize("name", false, &name_);
	d.Deserialize("caption", false, &caption_);
	d.Deserialize("description", false, &description_);
	d.Deserialize("source", false, &source_);
	d.Deserialize("icon", false, &icon_);
	d.Deserialize("attribution", false, &attribution_);
	d.Deserialize("actions", false, &actions_);
	d.Deserialize("likes", false, &likes_);
	d.Deserialize("created_time", false, &created_time_);
	d.Deserialize("updated_time", false, &updated_time_);
}

} // namespace Facebook
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
#include "PolymorphicObject.hpp"
#include "Deserializer.hpp"
#include "Status.hpp"
#include "Link.hpp"
#include "Photo.hpp"
#include "Video.hpp"

namespace LibFacebookCpp
{

void PolymorphicObject::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	if(!json.isConvertibleTo(Json::objectValue) || !json.isMember("type"))
	{
		throw UnexpectedException("!value.isConvertibleTo(Json::objectValue)");
	}
	else
	{
		Deserializer d(parent_obj, this, json);

		std::string type = json["type"].asString();

		// This is the funkiest thing. We have to lookup the object type
		if(type == "status")
		{
			ptr_ = boost::shared_ptr<Status>(new Status());
			d.DeserializeObject(true, static_cast<Status*>(ptr_.get()));
		}
		else if(type == "link")
		{
			ptr_ = boost::shared_ptr<Link>(new Link());
			d.DeserializeObject(true, static_cast<Link*>(ptr_.get()));
		}
		else if(type == "photo")
		{
			ptr_ = boost::shared_ptr<Photo>(new Photo());
			d.DeserializeObject(true, static_cast<Photo*>(ptr_.get()));
		}
		else if(type == "video")
		{
			ptr_ = boost::shared_ptr<Video>(new Video());
			d.DeserializeObject(true, static_cast<Video*>(ptr_.get()));
		}
		else
		{
			// GetInfoLog() << "Unable to map the object type: " << type;
		}
	}
}

} // namespace LibFacebookCpp
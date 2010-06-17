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
 *
 */

#include "Common.h"
#include "Deserializer.h"
#include "Photo.h"

namespace Facebook
{
	void Photo::Deserialize(const Json::Value &json)
	{
		Deserializer deserializer(json);

		deserializer.Deserialize("id", &id_);
		deserializer.Deserialize("from", &from_);
		deserializer.Deserialize("name", &name_);
		deserializer.Deserialize("picture", &picture_);
		deserializer.Deserialize("source", &source_);
		deserializer.Deserialize("height", &height_);
		deserializer.Deserialize("width", &width_);
		deserializer.Deserialize("link", &link_);
		deserializer.Deserialize("icon", &icon_);
		deserializer.Deserialize("created_time", &created_time_);
		deserializer.Deserialize("updated_time", &updated_time_);
	}
}
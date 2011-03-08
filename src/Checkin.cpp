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
#include "Checkin.hpp"

namespace LibFacebookCpp
{

void Checkin::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer d(parent_obj, this, json);

	// XXX: Uncomment stuff
	d.Deserialize("id", true, &id_);
	d.Deserialize("from", true, &from_);
	// d.Deserialize("tags", true, &tags_);
	// d.Deserialize("place", true, &place_);
	d.Deserialize("message", true, &message_);
	// d.Deserialize("application", true, &application_);
	d.Deserialize("created_time", true, &created_time_);
}

} // namespace LibFacebookCpp
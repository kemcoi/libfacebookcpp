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
#include "Venue.h"
#include "Deserializer.h"

namespace LibFacebookCpp
{

void Venue::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer d(parent_obj, this, json);

	d.Deserialize("street", false, &street_);
	d.Deserialize("city", false, &city_);
	d.Deserialize("state", false, &state_);
	d.Deserialize("zip", false, &zip_);
	d.Deserialize("country", false, &country_);
	d.Deserialize("latitude", false, &latitude_);
	d.Deserialize("longitude", false, &longitude_);
}

} // namespace LibFacebookCpp

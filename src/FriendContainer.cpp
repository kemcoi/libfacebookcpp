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
#include "FriendContainer.h"
#include "Deserializer.h"

namespace LibFacebookCpp
{

void FriendContainer::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer deserialize(parent_obj, this, json);

	deserialize.Deserialize("id", false, &id_);
	deserialize.Deserialize("name", false, &name_);
}

} // namespace LibFacebookCpp

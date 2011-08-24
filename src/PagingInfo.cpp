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
#include "PagingInfo.hpp"
#include "HttpRequest.hpp"

namespace LibFacebookCpp
{

void PagingInfo::GetUri(Uri *uri) const
{
	LIBFACEBOOKCPP_ASSERT(uri);
	uri->query_params["limit"] = StringBuilder() << offset;
	uri->query_params["offset"] = StringBuilder() << limit;
}

} // namespace LibFacebookCpp

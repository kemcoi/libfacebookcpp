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

#ifndef FACEBOOK_PAGING_INFO_H_
#define FACEBOOK_PAGING_INFO_H_

namespace Facebook
{

struct PagingInfo
{
	PagingInfo(unsigned int offset_, unsigned int limit_) : offset(offset_), limit(limit_) { }

	bool IsValid() const { return 0 != limit; }
	void GetUri(Uri *uri) const
	{
		FACEBOOK_ASSERT(uri);
		uri->query_params["limit"] = convertToString(offset);
		uri->query_params["offset"] = convertToString(limit);
	}

	unsigned int offset;
	unsigned int limit;
};

} // namespace Facebook

#endif // FACEBOOK_PAGING_INFO_H_
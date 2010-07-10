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
#include "ResponseBlob.h"

namespace LibFacebookCpp
{

ResponseBlob::ResponseBlob() : data_(NULL), bytes_(0)
{

}

ResponseBlob::~ResponseBlob()
{
	free(data_);
	data_ = NULL;
	bytes_ = 0;
}

void ResponseBlob::Realloc(size_t bytes)
{
	LIBFACEBOOKCPP_ASSERT(bytes >= 0);

	// Early-out
	if(bytes_ == bytes)
		return;

	// realloc(NULL, bytes) makes realloc work like malloc
	void *new_data = realloc(data_, bytes);

	if(!new_data)
		throw std::bad_alloc();

	data_ = new_data;
	bytes_= bytes;
}

} // namespace LibFacebookCpp

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

#ifndef LIBFACEBOOKCPP_RESPONSE_BLOB_H_
#define LIBFACEBOOKCPP_RESPONSE_BLOB_H_

namespace LibFacebookCpp
{

class LIBFACEBOOKCPP_API ResponseBlob
{
public: // ctor and ~()
	ResponseBlob();
	~ResponseBlob();

public: // public interface
	const void* GetData() const { return data_; }
	void* GetData() { return data_; }

	size_t GetLength() const { return bytes_; }

	const std::string& GetContentType() const { return content_type_; }
	void SetContentType(const std::string& content_type) { content_type_ = content_type; }

	void Realloc(size_t bytes);

private: // member variables
	void *data_;
	size_t bytes_;
	std::string content_type_;
};

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_RESPONSE_BLOB_H_

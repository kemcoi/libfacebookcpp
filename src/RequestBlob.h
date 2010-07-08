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

namespace Facebook
{

class RequestBlob
{
public: // ctor and ~()
	RequestBlob() : data_(NULL), bytes_(0)
	{
	}

	~RequestBlob()
	{
		free(data_);
		data_ = NULL;
		bytes_ = 0;
	}

public: // public interface
	const void* GetData() const { return data_; }
	void* GetData() { return data_; }
	size_t GetLength() const { return bytes_; }
	const std::string& GetContentType() const { return content_type_; }
	void SetContentType(const std::string& content_type) { content_type_ = content_type; }

	void Realloc(size_t bytes)
	{
		FACEBOOK_ASSERT(bytes >= 0);

		// realloc(NULL, bytes) makes realloc work like malloc
		void *new_data = realloc(data_, bytes);

		if(!new_data)
			// Exception for out of memory
			throw std::exception();

		data_ = new_data;
		bytes_= bytes;
	}

private: // member variables
	void *data_;
	size_t bytes_;
	std::string content_type_;
};

} // namespace Facebook
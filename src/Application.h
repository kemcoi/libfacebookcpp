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

class FACEBOOK_API Application : public AuthorizedObject
{
public: // accessors
	const std::string& Id() const { return id_; }
	const std::string& Name() const { return name_; }
	const std::string& Description() const { return description_; }
	const std::string& Category() const { return category_; }
	const std::string& Link() const { return link_; }

public: // connections
	// TODO: feed
	// TODO: posts

private: // member variables
	std::string id_;
	std::string name_;
	std::string description_;
	std::string category_;
	std::string link_;
};

} // namespace Facebook
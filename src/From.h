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

#ifndef FACEBOOK_FROM_H_
#define FACEBOOK_FROM_H_

#include "AuthorizedObject.h"

namespace Facebook
{

class FACEBOOK_API From : public AuthorizedObject
{
public: // public interface
	typedef AuthorizedObject inherited;
	From() { }

	//----------------------------------------------
	void Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json) FACEBOOK_OVERRIDE;

	//----------------------------------------------
	// Accessors
	const std::string& GetName() const { return name_; }
	const std::string& GetCategory() const { return category_; }
	const std::string& GetId() const { return id_; }

private: // private members
	std::string name_;
	std::string category_;
	std::string id_;
};

} // namespace Facebook

#endif
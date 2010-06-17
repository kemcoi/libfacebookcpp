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
 *
 */
#ifndef FACEBOOK_FROM_H_
#define FACEBOOK_FROM_H_

#include "Common.h"
#include "Object.h"

namespace Facebook
{
	class From : public Object
	{
	public: // public interface
		//----------------------------------------------
		void Deserialize(const Json::Value &json);

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
}

#endif
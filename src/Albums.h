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

#ifndef FACEBOOK_ALBUM_H_
#define FACEBOOK_ALBUM_H_

#include "Photo.h"

namespace Facebook
{
	class FACEBOOK_API Album: public AuthorizedObject
	{
	public:
		//----------------------------------------------
		Album() { }
		virtual ~Album() { }

		//----------------------------------------------
		void Deserialize(const Json::Value &json) OVERRIDE;

		//----------------------------------------------
		std::list<Facebook::Photo*>* getPhotoList() const;

		//----------------------------------------------
		// Accessors
		//TODO: Accessors for From class
		const std::string& getId() const { return id_; }
		const From& GetFrom() const { return from_; }
		const std::string& getName() const { return name_; }
		const std::string& getDescription() const { return description_; }
		const std::string& getLocation() const { return location_; }
		const std::string& getLink() const { return link_; }
		const unsigned int& getCount() const { return count_; }
		const std::string& getCreatedTime() const { return created_time_;}
		const std::string& getUpdatedTime_() const { return updated_time_; }

	private:
		std::string id_;
		From from_;
		std::string name_;
		std::string description_;
		std::string location_;
		std::string link_;
		unsigned int count_;
		std::string created_time_;
		std::string updated_time_;
	};
}

#endif
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

#ifndef FACEBOOK_VENUE_H_
#define FACEBOOK_VENUE_H_

#include "AuthorizedObject.h"

namespace Facebook
{

class FACEBOOK_API Venue : public AuthorizedObject
{
public: // accessors
	const std::string& GetStreet() const { return street_; }
	const std::string& GetCity() const { return city_; }
	const std::string& GetState() const { return state_; }
	const std::string& GetZip() const { return zip_; }
	const std::string& GetCountry() const { return country_; }
	float GetLatitude() const { return latitude_; }
	float GetLongitude() const { return longitude_; }

protected: // callback functions
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string street_;
	std::string city_;
	std::string state_;
	std::string zip_;
	std::string country_;
	float latitude_;
	float longitude_;
};

} // namespace Facebook

#endif // FACEBOOK_VENUE_H_

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
#ifndef LIBFACEBOOKCPP_LIST_H_
#define LIBFACEBOOKCPP_LIST_H_

#include "AuthorizedObject.h"
// XXX: UGLY!
#include "Deserializer.h"

namespace LibFacebookCpp
{

template<typename FBType>
class LIBFACEBOOKCPP_API List : public AuthorizedObject
{
public: // interface
	operator const std::list<FBType>& () const { return list_; }
	const std::list<FBType>& GetList() const { return list_; }

	void GetNext(List<FBType> * /* list */) const
	{
		// TODO:
	}

	void GetPrevious(List<FBType> * /* list */) const
	{
		// TODO:
	}

protected: // callbacks
	 void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
	 {
		Deserializer deserializer(parent_obj, this, json);

		deserializer.Deserialize("data", true, &list_);
		deserializer.Deserialize("next", false, &next_);
		deserializer.Deserialize("previous", false, &previous_);
	 }

private: // member variables
	std::list<FBType> list_;
	std::string next_;
	std::string previous_;
};

}
#endif

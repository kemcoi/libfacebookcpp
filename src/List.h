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
private: // private classes
	struct PagingUri
	{
	public: // public interface
		void Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
		{
			Deserializer d(parent_obj, json);

			d.Deserialize("previous", true, &previous);
			d.Deserialize("next", true, &next);
		}

		std::string previous;
		std::string next;
	};

public: // interface
	const std::list<FBType>& GetData() const { return data_; }

	void GetNext()
	{
		LIBFACEBOOKCPP_ASSERT(!paging_.next.empty());

		_GetConnection(paging_.next, this);
	}

	void GetPrevious()
	{
		LIBFACEBOOKCPP_ASSERT(!paging_.previous.empty());

		_GetConnection(paging_.previous, this);
	}

protected: // callbacks
	 void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
	 {
		Deserializer d(parent_obj, this, json);

		d.Deserialize("data", true, &data_);
		d.Deserialize("paging", false, &paging_);
	 }

private: // member variables
	std::list<FBType> data_;
	PagingUri paging_;
};

}
#endif

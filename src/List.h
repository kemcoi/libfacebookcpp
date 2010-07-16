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
#ifndef FACEBOOK_LIST_H_
#define FACEBOOK_LIST_H_

#include "AuthorizedObject.h"
#include "precompile.h"

namespace Facebook
{

template<typename FBType>
class FACEBOOK_API FBList:public AuthorizedObject
{
public:
protected:
	 void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);
private:
	std::list<FBType> dataList_;
	std::string	next_;
	std::string previous_;

};


void FBList<FBType>::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	dataList_.clear();
	Deserializer deserializer(*this, value);

	deserializer.Deserialize("data", true, dataList_);
	deserializer.Deserialize("next", false, next_);
	deserializer.Deserialize("previous", false, previous_);
}


}
#endif

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

#ifndef LIBFACEBOOKCPP_POLYMORPHIC_OBJECT_H_
#define LIBFACEBOOKCPP_POLYMORPHIC_OBJECT_H_

#include "AuthorizedObject.hpp"

namespace LibFacebookCpp
{

class LIBFACEBOOKCPP_API PolymorphicObject : public AuthorizedObject
{
public: // interface
	const shared_ptr<AuthorizedObject>& GetPtr() const { return ptr_; }

	const AuthorizedObject *operator *() const { return ptr_.get(); }
	AuthorizedObject *operator *() { return ptr_.get(); }
	const AuthorizedObject *operator->() const { return ptr_.get(); }
	AuthorizedObject *operator->() { return ptr_.get(); }

protected: // callback functions
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	shared_ptr<AuthorizedObject> ptr_;
};

// XXX: We need a way to regularize this. This is a bug in MSVC++
#ifdef _WIN32
template class LIBFACEBOOKCPP_API List<PolymorphicObject>;
#endif // _WIN32

} // namespace LibFacebookCpp

#endif // LIBFACEBOOKCPP_POLYMORPHIC_OBJECT_H_

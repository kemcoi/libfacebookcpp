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

#ifndef FACEBOOK_DESERIALIZER_H_
#define FACEBOOK_DESERIALIZER_H_

#include "Common.h"
#include "Object.h"
#include "Exception.h"

namespace Facebook
{
	class Deserializer
	{
	public: // public ctor
		Deserializer(const Json::Value &json) : json_(json)
		{
			if(!json_.isObject())
				throw InvalidArgument("json");

			if(json_.isMember("error"))
			{
				const Json::Value& value = json_["error"];
				throw FacebookException(value["type"].asString(), value["message"].asString());
			}
		}

	public: // public interface
		template<class TType>
		void Deserialize(const char *tag, TType *t)
		{
			assert(tag);
			assert(t);

			if(!json_.isMember(tag))
				throw UnexpectedException("json_[tag] is missing");

			t->Deserialize(json_[tag]);
		}

		template<>
		void Deserialize(const char *tag, std::string *str)
		{
			assert(tag);
			assert(str);

			if(!json_.isMember(tag))
				throw UnexpectedException("json_[tag] is missing");

			const Json::Value &value = json_[tag];

			if(!value.isConvertibleTo(Json::stringValue))
				throw UnexpectedException("!value.isConvertibleTo(Json::stringValue)");

			*str = value.asString();
		}

		template<>
		void Deserialize(const char *tag, unsigned int *uint)
		{
			assert(tag);
			assert(uint);

			if(!json_.isMember(tag))
				throw UnexpectedException("json_[tag] is missing");

			const Json::Value &value = json_[tag];

			if(!value.isConvertibleTo(Json::uintValue))
				throw UnexpectedException("!value.isConvertibleTo(Json::uintValue)");

			*uint = value.asUInt();
		}

	private: // assignment operator
		Deserializer& operator = (const Deserializer& rhs)
		{
			_UNUSED(rhs);
			throw NotSupportedException("Deserializer is not copyable");
		}

	private: // private members
		const Json::Value &json_;
	};
}

#endif // FACEBOOK_DESERIALIZER_H_

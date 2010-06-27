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

#ifndef FACEBOOK_DESERIALIZER_H_
#define FACEBOOK_DESERIALIZER_H_

#include "Object.h"
#include "Exception.h"
#include "AuthorizedObject.h"

// XXX: Clean up includes everywhere

namespace Facebook
{
	class Deserializer
	{
	public: // public ctor
		Deserializer(const AuthorizedObject &obj, const Json::Value &json) : json_(json), obj_(obj)
		{
			if(!json_.isObject())
				throw InvalidArgument("json");

			if(json_.isMember("error"))
			{
				const Json::Value& value = json_["error"];
				throw FacebookException(value["type"].asString(), value["message"].asString());
			}
		}

	private: // private helper functions
		template<class TType>
		void _DeserializeObject(const Json::Value &json, bool required, TType *t)
		{
			ASSERT(t);

			if(!json.isObject())
			{
				if(required)
					throw UnexpectedException("object is missing");
			}
			else
			{
				t->Deserialize(json);
				t->request_ = obj_.request_;
			}
		}

		template<>
		void _DeserializeObject(const Json::Value &json, bool required, std::string *str)
		{
			ASSERT(str);

			if(!json.isConvertibleTo(Json::stringValue))
			{
				if(required)
					throw UnexpectedException("!value.isConvertibleTo(Json::stringValue)");
			}
			else
			{
				*str = json.asString();
			}
		}

		template<>
		void _DeserializeObject(const Json::Value &json, bool required, unsigned int *uint)
		{
			ASSERT(uint);

			if(!json.isConvertibleTo(Json::uintValue))
			{
				if(required)
					throw UnexpectedException("!value.isConvertibleTo(Json::uintValue)");
			}
			else
			{
				*uint = json.asUInt();
			}
		}

		// XXX: Update exception comments

		template<class TType>
		void _DeserializeObject(const Json::Value &json, bool required, std::list<TType> *list)
		{
			ASSERT(list);

			if(!json.isConvertibleTo(Json::arrayValue))
			{
				if(required)
					throw UnexpectedException("!value.isConvertibleTo(Json::arrayValue)");
			}
			else
			{
				for(Json::UInt ii = 0; ii < json.size(); ++ii)
				{
					TType t;
					_DeserializeObject(json[ii], required, &t);
					list->push_back(t);
				}
			}
		}

		template<class TType>
		void _DeserializeObject(const Json::Value &json, bool required, std::vector<TType> *vector)
		{
			ASSERT(vector);

			if(!json.isConvertibleTo(Json::arrayValue))
			{
				if(required)
					throw UnexpectedException("!value.isConvertibleTo(Json::arrayValue)");
			}
			else
			{
				vector->reserve(json.size());

				for(Json::UInt ii = 0; ii < json.size(); ++ii)
				{
					TType t;
					_DeserializeObject(json[ii], required, &t);
					list->push_back(t);
				}
			}
		}

	public: // public interface
		template<class TType>
		void Deserialize(const char *tag, bool required, TType *t)
		{
			ASSERT(tag);
			ASSERT(t);

			if(!json_.isMember(tag))
			{
				if(required)
					throw UnexpectedException("json_[tag] is missing");
			}
			else
			{
				_DeserializeObject(json_[tag], required, t);
			}
		}


	private: // assignment operator
		Deserializer& operator = (const Deserializer& rhs)
		{
			_UNUSED(rhs);
			throw NotSupportedException("Deserializer is not copyable");
		}

	private: // private members
		const Json::Value &json_;
		const AuthorizedObject &obj_;
	};
}

#endif // FACEBOOK_DESERIALIZER_H_

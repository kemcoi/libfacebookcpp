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

#include "AuthorizedObject.h"
#include "Exception.h"

namespace Facebook
{

class Deserializer
{
public: // public ctor and ~()
	Deserializer(const AuthorizedObject &parent_obj, AuthorizedObject *obj, const Json::Value &json) : json_(json), obj_(parent_obj)
	{
		FACEBOOK_ASSERT(obj);

		if(!json_.isObject())
			throw InvalidArgument("json");

		if(json_.isMember("error"))
		{
			const Json::Value& value = json_["error"];
			throw FacebookException(value["type"].asString(), value["message"].asString());
		}

		obj->Init(parent_obj);

#ifdef _DEBUG
		std::vector<std::string> members = json.getMemberNames();

		for(std::vector<std::string>::const_iterator it = members.begin(); it != members.end(); ++it)
		{
			tags_.insert(std::pair<std::string, int>(*it, 0));
		}
#endif // _DEBUG
	}

	Deserializer(const AuthorizedObject &obj, const Json::Value &json) : json_(json), obj_(obj)
	{
		if(!json_.isObject())
			throw InvalidArgument("json");

		if(json_.isMember("error"))
		{
			const Json::Value& value = json_["error"];
			throw FacebookException(value["type"].asString(), value["message"].asString());
		}

#ifdef _DEBUG
		std::vector<std::string> members = json.getMemberNames();

		for(std::vector<std::string>::const_iterator it = members.begin(); it != members.end(); ++it)
		{
			tags_.insert(std::pair<std::string, int>(*it, 0));
		}
#endif // _DEBUG
	}

	~Deserializer()
	{
#ifdef _DEBUG
		for(std::map<std::string, int>::const_iterator it = tags_.begin(); it != tags_.end(); ++it)
		{
			if(it->second != 1)
			{
				GetInfoLog() << "Tag " << it->first << " had an access count of " << it->second;
			}
		}
#endif // _DEBUG
	}

private: // private helper functions
	template<class TType>
	void _DeserializeObject(const Json::Value &json, bool required, TType *t)
	{
		FACEBOOK_ASSERT(t);

		if(!json.isObject())
		{
			if(required)
				throw UnexpectedException("object is missing");
		}
		else
		{
			t->Init(obj_);
			t->Deserialize(obj_, json);
		}
	}

	template<>
	void _DeserializeObject(const Json::Value &json, bool required, std::string *str)
	{
		FACEBOOK_ASSERT(str);

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
	void _DeserializeObject(const Json::Value &json, bool required, int *value)
	{
		FACEBOOK_ASSERT(value);

		if(!json.isConvertibleTo(Json::intValue))
		{
			if(required)
				throw UnexpectedException("!value.isConvertibleTo(Json::intValue)");
		}
		else
		{
			*value = json.asInt();
		}
	}

	template<>
	void _DeserializeObject(const Json::Value &json, bool required, unsigned int *uint)
	{
		FACEBOOK_ASSERT(uint);

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

	template<>
	void _DeserializeObject(const Json::Value &json, bool required, float *f)
	{
		FACEBOOK_ASSERT(f);

		if(!json.isConvertibleTo(Json::realValue))
		{
			if(required)
				throw UnexpectedException("!value.isConvertibleTo(Json::realValue)");
		}
		else
		{
			*f = (float)json.asDouble();
		}
	}

	// XXX: Update exception comments

	template<class TType>
	void _DeserializeObject(const Json::Value &json, bool required, std::list<TType> *list)
	{
		FACEBOOK_ASSERT(list);

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
		FACEBOOK_ASSERT(vector);

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
		FACEBOOK_ASSERT(tag);
		FACEBOOK_ASSERT(t);

		if(!json_.isMember(tag))
		{
			if(required)
				throw UnexpectedException("json_[tag] is missing");
		}
		else
		{
#ifdef _DEBUG
			std::map<std::string, int>::iterator it = tags_.find(tag);

			if(it == tags_.end())
			{
				GetInfoLog() << "Unable to find " << tag << " in the list of members!";
			}
			else if(it->second != 0)
			{
				GetInfoLog() << "You are trying to access " << tag << " but it has been already deserialized!";
			}
			else
			{
				++(it->second);
			}
#endif // _DEBUG
			_DeserializeObject(json_[tag], required, t);
		}
	}

private: // assignment operator
	DISALLOW_COPY_AND_ASSIGN(Deserializer);

private: // private members
	const Json::Value &json_;
	const AuthorizedObject &obj_;
#ifdef _DEBUG
	std::map<std::string, int> tags_;
#endif // _DEBUG
};

} // namespace Facebook

#endif // FACEBOOK_DESERIALIZER_H_

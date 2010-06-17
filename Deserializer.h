#ifndef FACEBOOK_DESERIALIZER_H_
#define FACEBOOK_DESERIALIZER_H_

#include "Common.h"

namespace Facebook
{
	// TODO: The compiler complains that it can't generate an assignment operator for this object (on /W4)
	// We shut it up for now. This needs to be fixed
#pragma warning(push)
#pragma warning(disable: 4512)
	class Deserializer
	{
	public: // public ctor
		Deserializer(const Json::Value &json) : json_(json)
		{
			if(!json_.isObject())
				throw std::exception();
		}

	public: // public interface
		template<class TType>
		void Deserialize(const char *tag, TType *t)
		{
			assert(tag);
			assert(t);

			const Json::Value &value = json_[tag];
			if(value.isNull())
				throw std::exception();

			t->Deserialize(value);
		}

#define DESERIALIZER_INTRINSIC_TYPES(Type, JsonType, ConvertFunction) \
	template<> \
	void Deserialize(const char *tag, Type *t) \
	{ \
		assert(tag); \
		assert(t); \
		\
		const Json::Value &value = json_[tag]; \
		if(value.isNull()) \
		throw std::exception(); \
		\
		if(!value.isConvertibleTo(JsonType)) \
		throw std::exception(); \
		\
		*t = value.ConvertFunction(); \
	}

		DESERIALIZER_INTRINSIC_TYPES(std::string, Json::stringValue, asString);
		DESERIALIZER_INTRINSIC_TYPES(unsigned int, Json::uintValue, asUInt);

	private: // private members
		const Json::Value &json_;
	};
#pragma warning(pop)
}

#endif // FACEBOOK_DESERIALIZER_H_

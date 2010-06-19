#include "Common.h"
#include "Deserializer.h"
#include "From.h"

namespace Facebook
{
	void From::Deserialize(const Json::Value &json)
	{
		Deserializer deserializer(json);

		deserializer.Deserialize("name", &name_);
		deserializer.Deserialize("category", &category_);
		deserializer.Deserialize("id", &id_);
	}
}
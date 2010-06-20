#include "Common.h"
#include "Deserializer.h"
#include "From.h"

namespace Facebook
{
	void From::Deserialize(const Json::Value &json)
	{
		Deserializer deserializer(json);

		deserializer.Deserialize("name", false, &name_);
		deserializer.Deserialize("category", false, &category_);
		deserializer.Deserialize("id", false, &id_);
	}
}
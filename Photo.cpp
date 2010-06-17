#include "Common.h"
#include "Deserializer.h"
#include "Photo.h"

namespace Facebook
{
	void Photo::From::Deserialize(const Json::Value &json)
	{
		Deserializer deserializer(json);

		deserializer.Deserialize("name", &name_);
		deserializer.Deserialize("category", &category_);
		deserializer.Deserialize("id", &id_);
	}

	void Photo::Deserialize(const Json::Value &json)
	{
		Deserializer deserializer(json);

		deserializer.Deserialize("id", &id_);
		deserializer.Deserialize("from", &from_);
		deserializer.Deserialize("name", &name_);
		deserializer.Deserialize("picture", &picture_);
		deserializer.Deserialize("source", &source_);
		deserializer.Deserialize("height", &height_);
		deserializer.Deserialize("width", &width_);
		deserializer.Deserialize("link", &link_);
		deserializer.Deserialize("icon", &icon_);
		deserializer.Deserialize("created_time", &created_time_);
		deserializer.Deserialize("updated_time", &updated_time_);
	}
}
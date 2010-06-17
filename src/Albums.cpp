#include "Common.h"
#include "Deserializer.h"
#include "Albums.h"

namespace Facebook
{
	void Album::Deserialize( const Json::Value &json )
	{
		Deserializer d(json);

		d.Deserialize("id", &id_ );
		d.Deserialize("name", &name_);
		d.Deserialize("description", &description_);
		d.Deserialize("location", &location_);
		d.Deserialize("link", &link_);
		d.Deserialize("count", &count_);
		d.Deserialize("created_time", &created_time_);
		d.Deserialize("updated_time", &updated_time_);
	}

	std::list<Facebook::Photo*>* Album::getPhotoList() const
	{
		// TODO: Implement this
		return NULL;
	}
}
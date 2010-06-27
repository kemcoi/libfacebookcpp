#include "precompile.h"
#include "Deserializer.h"
#include "Albums.h"

namespace Facebook
{
	void Album::Deserialize( const Json::Value &json )
	{
		Deserializer d(*this, json);

		d.Deserialize("id", false,&id_ );
		d.Deserialize("name", false, &name_);
		d.Deserialize("description", false, &description_);
		d.Deserialize("location", false, &location_);
		d.Deserialize("link", false, &link_);
		d.Deserialize("count", false, &count_);
		d.Deserialize("created_time", false, &created_time_);
		d.Deserialize("updated_time", false, &updated_time_);
	}

	std::list<Facebook::Photo*>* Album::getPhotoList() const
	{
		// TODO: Implement this
		return NULL;
	}
}
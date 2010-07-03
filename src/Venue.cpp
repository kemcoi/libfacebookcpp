#include "precompile.h"
#include "Venue.h"
#include "Deserializer.h"

namespace Facebook
{

void Venue::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer d(parent_obj, this, json);

	d.Deserialize("street", false, &street_);
	d.Deserialize("city", false, &city_);
	d.Deserialize("state", false, &state_);
	d.Deserialize("zip", false, &zip_);
	d.Deserialize("country", false, &country_);
	d.Deserialize("latitude", false, &latitude_);
	d.Deserialize("longitude", false, &longitude_);
}

} // namespace Facebook

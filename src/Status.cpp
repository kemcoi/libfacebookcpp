#include "Common.h"
#include "Deserializer.h"
#include "Status.h"

namespace Facebook
{
	//-----------------------------------------------------------
	void Status::Deserialize( const Json::Value &json )
	{
		Deserializer deserializer(json);

		deserializer.Deserialize("id", &id_);
		deserializer.Deserialize("message", &message_);
		deserializer.Deserialize("updated_time", &updated_time_);

	}
}
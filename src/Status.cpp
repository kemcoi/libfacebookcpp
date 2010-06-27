#include "precompile.h"

#include "Deserializer.h"
#include "Status.h"

namespace Facebook
{
	//-----------------------------------------------------------
	void Status::Deserialize( const Json::Value &json )
	{
		Deserializer deserializer(*this, json);

		deserializer.Deserialize("id", false, &id_);
		deserializer.Deserialize("message", false, &message_);
		deserializer.Deserialize("updated_time", false, &updated_time_);

	}
}
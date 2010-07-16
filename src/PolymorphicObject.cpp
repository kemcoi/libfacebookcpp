#include "precompile.h"
#include "PolymorphicObject.h"
#include "Deserializer.h"
#include "Status.h"
#include "Link.h"
#include "Photo.h"
#include "Video.h"

namespace Facebook
{

void PolymorphicObject::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	if(!json.isConvertibleTo(Json::objectValue) || !json.isMember("type"))
	{
		throw UnexpectedException("!value.isConvertibleTo(Json::objectValue)");
	}
	else
	{
		Deserializer d(parent_obj, this, json);

		std::string type = json["type"].asString();

		// This is the funkiest thing. We have to lookup the object type
		if(type == "status")
		{
			ptr_ = shared_ptr<Facebook::Status>(new Facebook::Status());
			d.DeserializeObject(true, static_cast<Facebook::Status*>(ptr_.get()));
		}
		else if(type == "link")
		{
			ptr_ = shared_ptr<Facebook::Link>(new Facebook::Link());
			d.DeserializeObject(true, static_cast<Facebook::Link*>(ptr_.get()));
		}
		else if(type == "photo")
		{
			ptr_ = shared_ptr<Facebook::Photo>(new Facebook::Photo());
			d.DeserializeObject(true, static_cast<Facebook::Photo*>(ptr_.get()));
		}
		else if(type == "video")
		{
			ptr_ = shared_ptr<Facebook::Video>(new Facebook::Video());
			d.DeserializeObject(true, static_cast<Facebook::Video*>(ptr_.get()));
		}
		else
		{
			GetInfoLog() << "Unable to map the object type: " << type;
		}
	}
}

} // namespace Facebook
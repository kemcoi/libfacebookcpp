#include "precompile.h"
#include "PolymorphicObject.h"
#include "Deserializer.h"
#include "Status.h"
#include "Link.h"
#include "Photo.h"
#include "Video.h"

namespace LibFacebookCpp
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
			ptr_ = shared_ptr<Status>(new Status());
			d.DeserializeObject(true, static_cast<Status*>(ptr_.get()));
		}
		else if(type == "link")
		{
			ptr_ = shared_ptr<Link>(new Link());
			d.DeserializeObject(true, static_cast<Link*>(ptr_.get()));
		}
		else if(type == "photo")
		{
			ptr_ = shared_ptr<Photo>(new Photo());
			d.DeserializeObject(true, static_cast<Photo*>(ptr_.get()));
		}
		else if(type == "video")
		{
			ptr_ = shared_ptr<Video>(new Video());
			d.DeserializeObject(true, static_cast<Video*>(ptr_.get()));
		}
		else
		{
			GetInfoLog() << "Unable to map the object type: " << type;
		}
	}
}

} // namespace LibFacebookCpp
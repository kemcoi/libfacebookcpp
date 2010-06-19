
#include "User.h"
#include "Deserializer.h"
namespace Facebook
{

	void Facebook::User::Deserialize( const Json::Value &json )
	{
		Deserializer deserialize(json);

		deserialize.Deserialize("id",&id_);
		deserialize.Deserialize("first_name", &first_name_);
		deserialize.Deserialize("last_name", &last_name_);
		deserialize.Deserialize("name", &name_);
		deserialize.Deserialize("link", &link_);
		deserialize.Deserialize("about", &about_);
		deserialize.Deserialize("birthday", &birthday_);
		deserialize.Deserialize("work", &work_);
		deserialize.Deserialize("email", &email_);
		deserialize.Deserialize("website", &website_);
		deserialize.Deserialize("hometown", &hometown_);
		deserialize.Deserialize("gender", &gender_);
		deserialize.Deserialize("interested_in", &interested_in_);
		deserialize.Deserialize("meeting_for", &meeting_for_);
		deserialize.Deserialize("relationship_status", &relationship_status_);
		deserialize.Deserialize("religion", &religion_);
		deserialize.Deserialize("political", &political_);
		deserialize.Deserialize("verified", &verified_);
		deserialize.Deserialize("significant_other", &significant_other_);
		deserialize.Deserialize("timezone", &timezone_);

	}
}
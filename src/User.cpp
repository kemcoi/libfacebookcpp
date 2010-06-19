
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

	User* User::clone()
	{
		// do a deep copy
		std::tr1::shared_ptr<HttpRequest> clonedRequest_ = GetHttpRequest();
		Facebook::User* clonedUser = new Facebook::User(clonedRequest_);

		clonedUser->id_ = id_;
		clonedUser->first_name_ =first_name_;
		clonedUser->last_name_ = last_name_;
		clonedUser->name_ = name_;
		clonedUser->link_ = link_;
		clonedUser->about_ = about_;
		clonedUser->birthday_ = birthday_;
		clonedUser->work_ = work_;
		clonedUser->email_ = email_;
		clonedUser->website_ = website_;
		clonedUser->hometown_ = hometown_;
		clonedUser->gender_ = gender_;
		clonedUser->interested_in_ = interested_in_;
		clonedUser->meeting_for_ = meeting_for_;
		clonedUser->relationship_status_ = relationship_status_;
		clonedUser->religion_ = religion_;
		clonedUser->political_ = political_;
		clonedUser->verified_ = verified_;
		clonedUser->significant_other_ = significant_other_;
		clonedUser->timezone_ = timezone_;

		return clonedUser;
	}
}
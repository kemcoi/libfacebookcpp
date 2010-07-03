#include "AuthorizedObject.h"

namespace Facebook
{

class FACEBOOK_API Venue : public AuthorizedObject
{
public: // accessors
	const std::string& GetStreet() const { return street_; }
	const std::string& GetCity() const { return city_; }
	const std::string& GetState() const { return state_; }
	const std::string& GetZip() const { return zip_; }
	const std::string& GetCountry() const { return country_; }
	float GetLatitude() const { return latitude_; }
	float GetLongitude() const { return longitude_; }

protected: // callback functions
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string street_;
	std::string city_;
	std::string state_;
	std::string zip_;
	std::string country_;
	float latitude_;
	float longitude_;
};

} // namespace Facebook

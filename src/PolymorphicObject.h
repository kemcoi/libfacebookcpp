#include "AuthorizedObject.h"

namespace Facebook
{

class FACEBOOK_API PolymorphicObject : public AuthorizedObject
{
public: // interface
	const shared_ptr<AuthorizedObject>& GetPtr() const { return ptr_; }

	const AuthorizedObject *operator *() const { return ptr_.get(); }
	AuthorizedObject *operator *() { return ptr_.get(); }
	const AuthorizedObject *operator->() const { return ptr_.get(); }
	AuthorizedObject *operator->() { return ptr_.get(); }

protected: // callback functions
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	shared_ptr<AuthorizedObject> ptr_;
};

} // namespace Facebook

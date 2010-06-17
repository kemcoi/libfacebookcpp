#ifndef FACEBOOK_OBJECT_H_
#define FACEBOOK_OBJECT_H_

class Object
{
public: // public interface
	virtual void Deserialize(const Json::Value &json) = 0;
};

#endif // FACEBOOK_OBJECT_H_
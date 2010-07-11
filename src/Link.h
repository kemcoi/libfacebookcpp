#ifndef FACEBOOK_LINK_H_
#define FACEBOOK_LINK_H_

#include "AuthorizedObject.h"
#include "Friend.h"
#include "DateTime.h"

namespace LibFacebookCpp
{

class Comment;

class LIBFACEBOOKCPP_API Link : public AuthorizedObject
{
public: // accessors
	const std::string& GetId() const { return id_; }
	const Friend& GetFrom() const { return from_; }
	const std::string& GetLink() const { return link_; }
	const std::string& GetName() const { return name_; }
	const std::string& GetCaption() const { return caption_; }
	const std::string& GetDescription() const { return description_; }
	const std::string& GetMessage() const { return message_; }
	const DateTime& GetUpdatedTime() const { return updated_time_; }

public: // connection
	// XXX: Make sure all connections are const
	void GetComments(std::list<Comment> *list, const PagingInfo *paging = NULL) const;

	// XXX: comment callback
protected: // callback functions
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string id_;
	Friend from_;
	std::string link_;
	std::string name_;
	std::string caption_;
	std::string description_;
	std::string message_;
	DateTime updated_time_;
};

} // namespace LibFacebookCpp

#endif // FACEBOOK_LINK_H_
#ifndef FACEBOOK_LINK_H_
#define FACEBOOK_LINK_H_

#include "AuthorizedObject.h"
#include "FriendContainer.h"

namespace Facebook
{

class Comment;

class FACEBOOK_API Link : public AuthorizedObject
{
public: // accessors
	const std::string& Id() const { return id_; }
	const Facebook::FriendContainer& From() const { return from_; }
	// XXX: TODO: FUCKING FIX THIS
	const std::string& StrLink() const { return link_; }
	const std::string& Name() const { return name_; }
	const std::string& Caption() const { return caption_; }
	const std::string& Description() const { return description_; }
	const std::string& Message() const { return message_; }
	const std::string& UpdatedTime() const { return updated_time_; }

public: // connection
	// XXX: Make sure all connections are const
	void GetComments(std::list<Comment> *list, const PagingInfo *paging = NULL) const;

	// XXX: comment callback
protected: // callback functions
	void _Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json);

private: // member variables
	std::string id_;
	Facebook::FriendContainer from_;
	std::string link_;
	std::string name_;
	std::string caption_;
	std::string description_;
	std::string message_;
	std::string updated_time_;
};

} // namespace Facebook

#endif // FACEBOOK_LINK_H_
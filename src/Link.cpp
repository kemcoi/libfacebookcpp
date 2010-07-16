#include "precompile.h"
#include "Link.h"
#include "Deserializer.h"
#include "FriendContainer.h"
#include "Comment.h"
#include "PagingInfo.h"

namespace Facebook
{

void Link::GetComments(std::list<Comment> *list, const PagingInfo *paging /*= NULL*/) const
{
	_GetConnection(id_, "comments", list, paging);
}

void Facebook::Link::_Deserialize(const AuthorizedObject &parent_obj, const Json::Value &json)
{
	Deserializer d(parent_obj, this, json);

	d.Deserialize("id", true, &id_);
	d.Deserialize("from", false, &from_);
	d.Deserialize("link", false, &link_);
	d.Deserialize("name", false, &name_);
	d.Deserialize("caption", false, &caption_);
	d.Deserialize("description", false, &description_);
	d.Deserialize("message", false, &message_);
	d.Deserialize("updated_time", false, &updated_time_);
}

} // namespace Facebook
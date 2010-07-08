/*
 * Copyright (C) 2010 
 * Written by:
 * Aly Hirani <alyhirani@gmail.com>
 * James Chou <uohcsemaj@gmail.com>
 *
 * All Rights Reserved
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */

namespace Facebook
{

class FACEBOOK_API Application : public AuthorizedObject
{
public: // accessors
	const std::string& GetId() const { return id_; }
	const std::string& GetName() const { return name_; }
	const std::string& GetDescription() const { return description_; }
	const std::string& GetCategory() const { return category_; }
	const std::string& GetLink() const { return link_; }

public: // connections
	void GetFeedConnection(std::list<PolymorphicObject> *list, const PagingInfo *paging = NULL) const;
	void GetPostsConnection(std::list<Post> *list, const PagingInfo *paging = NULL) const;
	void GetPictureConnection(RequestBlob *blob) const;
	void GetTaggedConnection(std::list<PolymorphicObject> *list, const PagingInfo *paging = NULL) const;
	void GetLinksConnection(std::list<Link> *list, const PagingInfo *paging = NULL) const;
	void GetPhotosConnection(std::list<Photo> *list, const PagingInfo *paging = NULL) const;
	void GetAlbumsConnection(std::list<Album> *list, const PagingInfo *paging = NULL) const;
	void GetStatusesConnection(std::list<Status> *list, const PagingInfo *paging = NULL) const;
	void GetVideosConnection(std::list<Video> *list, const PagingInfo *paging = NULL) const;
	void GetNotesConnection(std::list<Note> *list, const PagingInfo *paging = NULL) const;
	void GetEventsConnection(std::list<Event> *list, const PagingInfo *paging = NULL) const;
	// TODO: subscriptions
	// TODO: insights

private: // member variables
	std::string id_;
	std::string name_;
	std::string description_;
	std::string category_;
	std::string link_;
};

} // namespace Facebook
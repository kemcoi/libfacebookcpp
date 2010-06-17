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
 *
 */

#include "Session.h"

int main()
{
	Json::Reader reader;
	Json::Value value;

	reader.parse("{   \"id\": \"98423808305\",   \"from\": {      \"name\": \"Coca-Cola\",      \"category\": \"Consumer_products\",      \"id\":\"40796308305\"   },   \"name\": \"A spectacular artwork made solely from used aluminum cans has been unveiledon top of the chalk cliffs of the Sussex coastline to mark the beginning of Recycle Week.\",  \"picture\":\"http://photos-e.ak.fbcdn.net/hphotos-ak-snc1/hs085.snc1/5041_98423808305_40796308305_1960517_6704612_.jpg\",   \"source\":\"http://sphotos.ak.fbcdn.net/hphotos-ak-snc1/hs085.snc1/5041_98423808305_40796308305_1960517_6704612_n.pg\",   \"height\": 402,   \"width\": 604,   \"link\": \"http://www.facebook.com/photo.php?pid=1960517&id=40796308305\",   \"icon\":\"http://static.ak.fbcdn.net/rsrc.php/z2E5Y/hash/8as8iqdm.gif\",   \"created_time\":\"2009-06-25T19:14:25+0000\",   \"updated_time\": \"2009-06-25T19:17:30+0000\"}", value);

	Facebook::Photo *photo = new Facebook::Photo();

	photo->Deserialize(value);

	return 0;
}
#include "Common.h"
#include "HTTPRequest.h"

#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

namespace Facebook
{
	std::auto_ptr<Json::Value> HttpRequest::GetResponse()
	{
		// First build the final url

		std::ostringstream oss_url;

		oss_url << GetUrl();

		if(query_params_.size() > 0)
		{
			oss_url << "?";

			// Due to the check above, we must have at least one element

			QueryParamList::const_iterator it = query_params_.begin();

			oss_url << curlpp::escape(it->first) << "=" << curlpp::escape(it->second);
			++it;

			while(it != query_params_.end())
			{
				oss_url << curlpp::escape(it->first) << "=" << curlpp::escape(it->second);
				++it;
			}
		}

		curlpp::Easy curl;
		curl.setOpt(curlpp::options::Url(oss_url.str()));

		std::stringstream oss_request;

		// This performs the request and dumps the output to the stringstream
		oss_request << curl;

		std::auto_ptr<Json::Value> value(new Json::Value);
		Json::Reader reader;
		reader.parse(oss_request, *value);

		return value;
	}
}

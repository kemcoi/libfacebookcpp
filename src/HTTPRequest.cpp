#include "Common.h"
#include "HTTPRequest.h"

#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include "Exception.h"

namespace Facebook
{
	std::string Uri::GetUri() const
	{
		if(base_uri.empty())
			throw InvalidArgument("base_uri");

		std::ostringstream oss;

		oss << base_uri;

		if(query_params.size() > 0)
		{
			oss << "?";

			// Due to the check above, we must have at least one element

			QueryParamList::const_iterator it = query_params.begin();

			oss << curlpp::escape(it->first) << "=" << curlpp::escape(it->second);
			++it;

			while(it != query_params.end())
			{
				oss << curlpp::escape(it->first) << "=" << curlpp::escape(it->second);
				++it;
			}
		}

		return oss.str();
	}

	std::auto_ptr<Json::Value> HttpRequest::GetResponse(const Uri& uri)
	{
		// First build the final url

		curlpp::Easy curl;
		curl.setOpt(curlpp::options::Url(uri.GetUri()));
		// TODO: We shouldn't be disabling this. Instead, implementing our own Ctx
		curl.setOpt(curlpp::options::SslVerifyPeer(false));

		std::stringstream oss;

		// This performs the request and dumps the output to the stringstream
		oss << curl;

		std::auto_ptr<Json::Value> value(new Json::Value);
		Json::Reader reader;
		reader.parse(oss, *value);

		return value;
	}
}

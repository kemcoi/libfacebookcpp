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

			QueryParamMap::const_iterator it = query_params.begin();

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

	namespace HttpUtils
	{
		void DecomposeUri(const std::string& str, Uri& uri)
		{
			uri.Clear();

			std::string::size_type lastPos = str.find('?');

			if(std::string::npos == lastPos)
			{
				uri.base_uri = str;
			}
			else
			{
				uri.base_uri = str.substr(0, lastPos);

				// XXX: This is an inefficient algorithm. Need to speed it up

				std::list<std::string> list;

				++lastPos;
				std::string::size_type pos = str.find_first_of("&=", lastPos);

				while (std::string::npos != pos || std::string::npos != lastPos)
				{
					list.push_back(str.substr(lastPos, pos - lastPos));
					lastPos = str.find_first_not_of("&=", pos);
					pos = str.find_first_of("&=", lastPos);
				}

				assert(list.size() % 2 == 0);

				for(std::list<std::string>::const_iterator it = list.begin(); it != list.end();)
				{
					std::string str1 = *it++;
					std::string str2 = *it++;
					uri.query_params.insert(std::pair<std::string, std::string>(curlpp::unescape(str1), curlpp::unescape(str2)));
				}
			}
		}
	}

	void HttpRequest::GetResponse(const Uri& uri, Json::Value &value)
	{
		// First build the final url

		curlpp::Easy curl;
		Logger::URLLog(LOG_PARAMS, uri.GetUri());
		curl.setOpt(curlpp::options::Url(uri.GetUri()));
		// TODO: We shouldn't be disabling this. Instead, implementing our own Ctx
		curl.setOpt(curlpp::options::SslVerifyPeer(false));

		std::stringstream oss;

		// This performs the request and dumps the output to the stringstream
		oss << curl;

		Json::Reader reader;
		reader.parse(oss, value);
	}
}

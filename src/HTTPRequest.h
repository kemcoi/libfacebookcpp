#ifndef FACEBOOK_HTTPREQUEST_H_
#define FACEBOOK_HTTPREQUEST_H_

#include <list>

namespace Facebook
{
	class HttpRequest
	{
	public: // public types
		typedef std::list<std::pair<std::string, std::string>> QueryParamList;

	public: // public interface
		void SetUrl(const std::string& str) { str_ = str; }
		const std::string GetUrl() const { return str_; }

		QueryParamList& GetQueryParams() { return query_params_; } 
		const QueryParamList& GetQueryParams() const { return query_params_; }

		std::auto_ptr<Json::Value> GetResponse();

	private: // member variables
		std::string str_;
		QueryParamList query_params_;
	};
}

#endif // FACEBOOK_HTTPREQUEST_H_

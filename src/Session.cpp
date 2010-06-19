#include "sstream"
#include "Common.h"
#include "Session.h"
#include "HTTPRequest.h"

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>


namespace Facebook
{
	//----------------------------------------------
	// Constructor
	Session::Session(std::string redirectedURL)
	{
		Logger::FacebookLog(FB_Info, LOG_PARAMS, "Initializing Session");
		logger_ = new Facebook::Logger();
		HtppHandler_ = new HttpRequest(redirectedURL);

		// Yes, I'm going to abuse the const_cast here temporarily.
		Logger::FacebookLog(FB_Info, LOG_PARAMS, const_cast<char*>(redirectedURL.c_str()));
		
	}
	//----------------------------------------------
	void Session::Destroy()
	{
		delete this;
	}

	//----------------------------------------------
	Facebook::Session::~Session()
	{
		//TODO
	}

	const std::string Session::GetAuthenticationURL(const std::string clientID, const std::string redirectURI, const std::string type, const std::string display)
	{
		Logger::FacebookLog<LogType>(FB_Info, LOG_PARAMS,  "Creating Authentication URL");
		static const std:: string s_authorization_uri = "https://graph.facebook.com/oauth/authorize";
		std::stringstream oss;

		oss << s_authorization_uri << "?client_id=" << curlpp::escape(clientID) << "&redirect_uri=" <<
			curlpp::escape(redirectURI); 
			
			if(!type.empty())
			{	
				oss << "&type=" << curlpp::escape(type) ;
			}

			if(!display.empty())
			{
				oss<< "&display=" << curlpp::escape(display);
			}

		return oss.str();
	}

	Session* Session::Authenticate(std::string redirectedURL)
	{	
		Facebook::Uri redirectedParams;
		HttpUtils::DecomposeUri(redirectedURL, redirectedParams); // THANK YOU ALY

		// Hardcode this for now
		Uri::QueryParamMap::const_iterator it = redirectedParams->query_params.find("code");

		if(!redirectedParams->query_params.front().second.empty())
		{
			// no access token
			Logger::FacebookLog(FB_Warn, LOG_PARAMS, "No access_token found");

			// XXX: Throw an exception here?
			return NULL;
		}
		else
		{
			Logger::FacebookLog(FB_Info, LOG_PARAMS, "Found Access Token");
			return new Facebook::Session(redirectedParams->query_params.front().second);
		}	
	}

	const Facebook::User* Session::getCurrentUser()
	{
	
		return NULL;
	}
}

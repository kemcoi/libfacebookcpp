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
	Session::Session(std::string accessToken): cachedUser_(NULL)
	{
		Logger::FacebookLog(FB_Info, LOG_PARAMS, "Initializing Session");
		logger_ = new Facebook::Logger();
		HttpHandler_ = std::tr1::shared_ptr<HttpRequest>(new HttpRequest(accessToken));

		// Yes, I'm going to abuse the const_cast here temporarily.
		Logger::FacebookLog(FB_Info, LOG_PARAMS, accessToken.c_str());
		
	}
	//----------------------------------------------
	void Session::Destroy()
	{
		delete this;
	}

	//----------------------------------------------
	Facebook::Session::~Session()
	{
		delete logger_; logger_ = NULL;
	}

	//----------------------------------------------
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

	//----------------------------------------------
	Session* Session::Authenticate(std::string redirectedURL)
	{	
		// XXX: Hack
		redirectedURL[redirectedURL.find_first_of('#')] = '?';

		Facebook::Uri redirectedParams;
		HttpUtils::DecomposeUri(redirectedURL, redirectedParams); // THANK YOU ALY

		// Hardcode this for now
		QueryParamMap::const_iterator it = redirectedParams.query_params.find("access_token");

		if(it == redirectedParams.query_params.end())
		{
			// no access token
			Logger::FacebookLog(FB_Warn, LOG_PARAMS, "No access_token found");

			// XXX: Throw an exception here?
			return NULL;
		}
		else
		{
			Logger::FacebookLog(FB_Info, LOG_PARAMS, "Found Access Token");
			return new Facebook::Session(it->second);
		}	
	}

	//----------------------------------------------
	const Facebook::User* Session::getCurrentUser()
	{
		Facebook::User* newUser = new Facebook::User(HttpHandler_);
		Facebook::Uri userLink;

		userLink.base_uri = "https://graph.facebook.com/me/";
		userLink.query_params["access_token"] = HttpHandler_->access_token_;
		
		Json::Value userValues;

		HttpHandler_->GetResponse(userLink, userValues);
		newUser->Deserialize(userValues);

		
		// let's keep a copy on our sesion object
		if( NULL != cachedUser_)
		{
			cachedUser_ = newUser->clone();
		}
 		return newUser;
	}

	//----------------------------------------------
}

#include "sstream"
#include "Common.h"
#include "Session.h"
#include "HTTPRequest.h"
#include "Exception.h"

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>


namespace Facebook
{
	//----------------------------------------------
	// Constructor
	Session::Session(std::string accessToken): cachedUser_(NULL)
	{
		GetInfoLog() << "Initializing Session";
		logger_ = new Facebook::Logger();
		HttpHandler_ = std::tr1::shared_ptr<HttpRequest>(new HttpRequest(accessToken));
		GetInfoLog() << accessToken.c_str();
		
	}
	//----------------------------------------------
	void Session::Destroy()
	{
		delete this;
	}

	//----------------------------------------------
	Facebook::Session::~Session()
	{
		delete cachedUser_; cachedUser_ = NULL;
		delete logger_; logger_ = NULL;
	}

	//----------------------------------------------
	const std::string Session::GetAuthenticationURL(const std::string clientID, const std::string redirectURI, const std::string type, const std::string display)
	{
		GetInfoLog() << "Creating Authentication URL";
		
		static const char *authorization_uri = "https://graph.facebook.com/oauth/authorize";
		std::stringstream oss;

		oss << authorization_uri << "?client_id=" << curlpp::escape(clientID) << "&redirect_uri=" <<
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
			GetWarnLog() << "No access_token found";
			throw UnexpectedException("Unable to find access token from redirected URL");
		}
		else
		{
			GetInfoLog() << "Found Access Token";
			return new Facebook::Session(it->second);
		}	
	}

	//----------------------------------------------
	const Facebook::User* Session::getCurrentUser()
	{
		Facebook::User* newUser = new Facebook::User();
		Facebook::Uri userLink;

		userLink.base_uri = "https://graph.facebook.com/me/";
		userLink.query_params["access_token"] = HttpHandler_->access_token_;
		
		Json::Value userValues;

		HttpHandler_->GetResponse(userLink, userValues);
		newUser->Deserialize(userValues);

		// let's keep a copy on our session object
		if( NULL == cachedUser_)
		{
			cachedUser_ = newUser->clone();
		}
 		return newUser;
	}

	//----------------------------------------------
}

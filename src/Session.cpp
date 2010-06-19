#include "sstream"
#include "Common.h"
#include "Session.h"

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

namespace Facebook
{
	//----------------------------------------------
	// Constructor
	Session::Session()
	{
		logger_ = new Facebook::Logger();
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
		Logger::FacebookLog(FB_Info, "Creating Authentication URL");
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
}

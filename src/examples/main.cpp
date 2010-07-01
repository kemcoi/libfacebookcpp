#include <iostream>
#include <Facebook.h>

int main()
{
	{
		// let's use this for now
		std::string	clientid = "232486072316";
		std::string redirectURI = "http://www.facebook.com/connect/login_success.html";
		std::string url = Facebook::Session::GetAuthenticationURL(clientid, redirectURI, "user_agent", std::string());

		std::cout << "PASTE THIS INTO YOUR BROWSER TO ACCEPT" << std::endl;
		std::cout << std::endl << url << std::endl;
		std::string redirectURL;
		system("pause"); // VS Debug

		std::cout << "COPY THE REDIRECTED URL INTO HERE";
		std::cin >> redirectURL;

		std::auto_ptr<Facebook::Session> session_(Facebook::Session::Authenticate(redirectURL));
		std::auto_ptr<const Facebook::User> user_(session_->getCurrentUser());
		std::list<Facebook::FriendContainer> list_;

		user_->getFriendsList(5, 20, list_);

		std::auto_ptr<const Facebook::User> jonLai(session_->getUserByID(std::string("506828136")));
		system("pause"); // VS Debug
	}

	return 0;
}

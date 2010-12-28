#include <iostream>
#include <fstream>
#include <string>
#include <LibFacebookCpp.hpp>

namespace Facebook = LibFacebookCpp;

std::string GetClientId()
{
	std::ifstream fin("clientid.txt");
	std::string id;
	getline(fin, id);
	return id;
}

int main()
{
	// let's use this for now
	std::string	clientid = GetClientId();
	std::string redirectURI = "http://www.facebook.com/connect/login_success.html";
	/*Facebook::ExtendedPermissions scope;
	scope.RequestPermission(Facebook::EP_EMAIL);
	scope.RequestPermission(Facebook::EP_USER_PHOTOS);
	scope.RequestPermission(Facebook::EP_READ_MAILBOX);*/

	std::string url = Facebook::Session::GetAuthenticationURL(clientid, redirectURI, "user_agent", std::string());

	std::cout << "PASTE THIS INTO YOUR BROWSER TO ACCEPT" << std::endl;
	std::cout << std::endl << url << std::endl;
	std::string redirectURL;

	std::cout << "Press any key to continue...." << std::endl;
	std::cin.get();

	std::cout << "COPY THE REDIRECTED URL INTO HERE";
	std::cin >> redirectURL;

	Facebook::Session session_(redirectURL);

	Facebook::User user;
	session_.GetCurrentUser(&user);

	Facebook::ResponseBlob blob;
	user.GetPictureConnection(Facebook::PS_LARGE, &blob);

	Facebook::List<Facebook::PolymorphicObject> homeList;
	user.GetHomeConnection(&homeList);

	do 
	{
		// TODO: FIX THIS INFINITE LOOP
		const std::list<Facebook::PolymorphicObject>& list = homeList.GetData();
		std::cout << homeList.GetData().size() << std::endl;

	} while (homeList.GetNext());

	std::cout << homeList.GetData().size() << std::endl;

	Facebook::List<Facebook::Album> albumList;
	user.GetAlbumsConnection(&albumList);

	Facebook::List<Facebook::Message> messageInbox;
	user.GetInboxConnection(&messageInbox);

	homeList.GetNext();

	std::cout << "Press any key to continue..." << std::endl;
	std::cin.get();

	return 0;
}

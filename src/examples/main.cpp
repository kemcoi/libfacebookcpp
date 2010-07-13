#include <iostream>
#include <LibFacebookCpp.h>

namespace Facebook = LibFacebookCpp;

#include <Windows.h>

int main()
{
	{
		// let's use this for now
		std::string	clientid = "232486072316";
		std::string redirectURI = "http://www.facebook.com/connect/login_success.html";
		Facebook::ExtPermissions scope;
		scope.requestPermission(Facebook::FBEP_EMAIL);
		scope.requestPermission(Facebook::FBEP_USER_PHOTOS);
		scope.requestPermission(Facebook::FBEP_READ_MAILBOX);

		std::string url = Facebook::Session::GetAuthenticationURL(clientid, redirectURI, "user_agent", std::string(), scope);

		std::cout << "PASTE THIS INTO YOUR BROWSER TO ACCEPT" << std::endl;
		std::cout << std::endl << url << std::endl;
		std::string redirectURL;
		system("pause"); // VS Debug

		std::cout << "COPY THE REDIRECTED URL INTO HERE";
		std::cin >> redirectURL;

		std::auto_ptr<Facebook::Session> session_(Facebook::Session::Authenticate(redirectURL));

		Facebook::User user;
		session_->GetCurrentUser(&user);

		Facebook::ResponseBlob blob;
		user.GetPictureConnection(Facebook::PS_LARGE, &blob);

		std::list<Facebook::PolymorphicObject> homeList;
		user.GetHomeConnection(&homeList);

		//HANDLE handle = CreateFile(TEXT("C:\\Users\\Aly Hirani\\Desktop\\a.jpg"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
		//DWORD dw = 0;
		//WriteFile(handle, blob.GetData(), blob.GetLength(), &dw, NULL);
		//CloseHandle(handle);

		std::list<Facebook::Album> albumList;
		user.GetAlbumsConnection(&albumList);
		std::list<Facebook::Message> messageInbox;
		user.GetInboxConnection(&messageInbox);

		system("pause"); // VS Debug
	}

	return 0;
}

#include <iostream>
#include <Facebook.h>

#include <Windows.h>

int main()
{
	{
		// let's use this for now
		std::string	clientid = "232486072316";
		std::string redirectURI = "http://www.facebook.com/connect/login_success.html";
		std::list<std::string>scopeList;
		scopeList.push_front("read_mailbox");
		scopeList.push_front("user_photos");
		scopeList.push_front("user_videos");
		std::string url = Facebook::Session::GetAuthenticationURL(clientid, redirectURI, "user_agent", std::string(), scopeList);

		std::cout << "PASTE THIS INTO YOUR BROWSER TO ACCEPT" << std::endl;
		std::cout << std::endl << url << std::endl;
		std::string redirectURL;
		system("pause"); // VS Debug

		std::cout << "COPY THE REDIRECTED URL INTO HERE";
		std::cin >> redirectURL;

		std::auto_ptr<Facebook::Session> session_(Facebook::Session::Authenticate(redirectURL));

		Facebook::User user;
		session_->GetCurrentUser(&user);

		Facebook::Blob blob;
		user.GetPicture(&blob);

		HANDLE handle = CreateFile(TEXT("C:\\Users\\Aly Hirani\\Desktop\\a.jpg"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
		DWORD dw = 0;
		WriteFile(handle, blob.GetData(), blob.GetLength(), &dw, NULL);
		CloseHandle(handle);

		std::list<Facebook::Album> albumList;

		system("pause"); // VS Debug
	}

	return 0;
}

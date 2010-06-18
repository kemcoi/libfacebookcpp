#include "Common.h"
#include "Session.h"


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

	Session* Session::getSession()
	{
		//TODO
		return new Session();
	}
}

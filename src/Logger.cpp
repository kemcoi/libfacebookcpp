
#include "Logger.h"
#include <iostream>

namespace Facebook
{
	Logger::Logger()
	{
		instance_ = logInstances; logInstances++; // ghetto instancing
		std::cout << "Initializing Logger " << instance_ << std::endl;
		std:: cout << curlpp::libcurlVersion() << std::endl;

	}

	Logger::~Logger()
	{
		std::cout<< "Destroying Logger Instance " << instance_ << std::endl;
	}
}
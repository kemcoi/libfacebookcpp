
#include "Logger.h"
#include <curlpp/cURLpp.hpp>
#include <iostream>

namespace Facebook
{
	static int logInstances = 1;

	Logger::Logger()
	{
		instance_ = logInstances; logInstances++; // ghetto instancing
		std::cout << "Initializing Logger " << instance_ << std::endl;
		std::cout << curlpp::libcurlVersion() << std::endl;

	}

	Logger::~Logger()
	{
		std::cout<< "Destroying Logger Instance " << instance_ << std::endl;
	}
}
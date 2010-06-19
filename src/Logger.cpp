
#include "Logger.h"
#include <curlpp/cURLpp.hpp>
#include <iostream>

namespace Facebook
{
	static int logInstances = 1;

	Logger::Logger()
	{
		instance_ = logInstances; logInstances++; // ghetto instancing
		FacebookLog(FB_Info, "Initializing Logger ");
	}

	Logger::~Logger()
	{
		FacebookLog(FB_Info, "Destroying Logger Instance ");
	}

	// Make this va_list?
	void Logger::FacebookLog( LogType type, char* logString )
	{
		std::cout<< type << logString << std::endl;
	}
}
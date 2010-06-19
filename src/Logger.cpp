
#include "Logger.h"
#include <curlpp/cURLpp.hpp>
#include <iostream>

namespace Facebook
{
	static int logInstances = 1;

	Logger::Logger()
	{
		instance_ = logInstances; logInstances++; // ghetto instancing
		FacebookLog(FB_Debug, "Initializing Logger");
	}

	Logger::~Logger()
	{
		FacebookLog(FB_Info, "Destroying Logger Instance ");
	}

	// Make this va_list?
	void Logger::FacebookLog(LogType type, int lineNumber, const char* file, char* logString)
	{
		file;
		std::cout<< "Line:" << lineNumber<< " " << type << logString << std::endl;
	}
}
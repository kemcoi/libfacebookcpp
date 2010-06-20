
#include "Logger.h"
#include <curlpp/cURLpp.hpp>
#include <iostream>

namespace Facebook
{
	static int logInstances = 1;

	Logger::Logger()
	{
		instance_ = logInstances; logInstances++; // ghetto instancing
		FacebookLog<LogType>(FB_Info, LOG_PARAMS, "Initializing Logger");
	}

	Logger::~Logger()
	{
		FacebookLog<LogType>(FB_Info, LOG_PARAMS, "Destroying Logger Instance ");
	}
	
}
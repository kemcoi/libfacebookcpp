#include "precompile.h"
#include "Logger.h"
#include <curlpp/cURLpp.hpp>
#include <iostream>

namespace Facebook
{
	Logger logInstance;

	Logger::Logger()
	{
		for(size_t ii = 0; ii < NUMELMS(stream_); ++ii)
		{
			stream_[ii].rdbuf(std::cout.rdbuf());
		}
	}

	std::ostream& Logger::GetLog( FB_LOGLEVEL level, int lineNumber, const char* file )
	{
		ASSERT(level >= FB_LOGLEVEL_ERROR && level < FB_LOGLEVEL_COUNT);

		static const char *s_level[] = {
			"Error: ", "Warning: ", "Info: ", "Debug: "
		};

		CASSERT(NUMELMS(s_level) == FB_LOGLEVEL_COUNT);

		stream_[level] << std::endl << s_level[level];

		if(level <= FB_LOGLEVEL_WARN)
			stream_[level] << " @ " << file << ":" << lineNumber << std::endl;

		return stream_[level];
	}
}
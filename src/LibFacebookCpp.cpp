#include "precompile.hpp"
#include "Version.h"

namespace LibFacebookCpp
{

const char *GetMajorVersion()
{
	return LF_MAJOR;
}

const char *GetMinorVersion()
{
	return LF_MINOR;
}

const char *GetRevisionVersion()
{
	return LF_REVISION;
}

} // namespace LibFacebookCpp

#include "precompile.hpp"
#include "Version.hpp"

namespace LibFacebookCpp
{

const char *GetMajorVersion()
{
	return LIBFACEBOOKCPP_VERSION_MAJOR;
}

const char *GetMinorVersion()
{
	return LIBFACEBOOKCPP_VERSION_MINOR;
}

const char *GetRevisionVersion()
{
	return LIBFACEBOOKCPP_VERSION_REVISION;
}

} // namespace LibFacebookCpp

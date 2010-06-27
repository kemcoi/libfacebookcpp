#include "precompile.h"
#include <cassert>
#include <crtdbg.h>
#include "Exception.h"

void _assert(bool x)
{
	assert(x);
}

#ifdef DEBUG
void BeginMemoryTracker()
{
}

void EndMemoryTracker()
{
}
#else // DEBUG
void BeginMemoryTracker()
{
}

void EndMemoryTracker()
{
	if(_CrtDumpMemoryLeaks())
		DebugBreak();
}
#endif // DEBUG

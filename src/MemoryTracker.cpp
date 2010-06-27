#include "MemoryTracker.h"
#include <crtdbg.h>
#include "Exception.h"

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

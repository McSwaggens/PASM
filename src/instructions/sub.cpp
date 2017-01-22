#include "sub.h"
#include "../engine.h"

void SUB::Execute ()
{
	engine->stack->Sub ();
}

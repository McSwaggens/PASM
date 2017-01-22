#include "neg.h"
#include "../engine.h"

void NEG::Execute ()
{
	engine->stack->Sub ();
}

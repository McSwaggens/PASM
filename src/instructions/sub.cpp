#include "sub.h"
#include "../engine.h"

void SUB::Execute ()
{
	engine->stack->Sub ();
}

void SUBI::Execute ()
{
	engine->stack->Sub_i ();
}

void SUBF::Execute ()
{
	engine->stack->Sub_f ();
}

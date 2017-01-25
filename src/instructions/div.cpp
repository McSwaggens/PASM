#include "div.h"
#include "../engine.h"

void DIV::Execute ()
{
	engine->stack->Div ();
}

void DIVI::Execute ()
{
	engine->stack->Div_i ();
}

void DIVF::Execute ()
{
	engine->stack->Div_f ();
}

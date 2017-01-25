#include "add.h"
#include "../engine.h"

void ADD::Execute ()
{
	engine->stack->Add ();
}

void ADDI::Execute ()
{
	engine->stack->Add_i ();
}

void ADDF::Execute ()
{
	engine->stack->Add_f ();
}

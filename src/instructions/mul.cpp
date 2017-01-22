#include "mul.h"
#include "../engine.h"

void MUL::Execute ()
{
	engine->stack->Mul ();
}

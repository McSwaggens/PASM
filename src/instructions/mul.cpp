#include "mul.h"
#include "../engine.h"

void MUL::Execute ()
{
	engine->stack->Mul ();
}

void MULI::Execute ()
{
	engine->stack->Mul_i ();
}

void MULF::Execute ()
{
	engine->stack->Mul_f ();
}

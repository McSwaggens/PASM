#include "push.h"
#include "../engine.h"


PUSH::PUSH (uint64_t number)
{
	this->number = number;
}

void PUSH::Execute()
{
	engine->stack->Push(number);
}

// Signed

PUSHI::PUSHI (int64_t number)
{
	this->number = number;
}

void PUSHI::Execute()
{
	engine->stack->Push(number);
}

// Floating point

PUSHF::PUSHF (double number)
{
	this->number = number;
}

void PUSHF::Execute()
{
	engine->stack->Push(number);
}

#include "push.h"
#include "../engine.h"

void StackCheck ()
{
	if (engine->stack->GetPosition() == 255)
	{
		printf ("STACK OVERFLOW!\nREACHED 255 (MAX FOR 1 BYTE)\nTry not pushing too much into the CPU stack?\nExiting engine...!\n");
		throw 0;
	}
}

PUSH::PUSH (uint64_t number)
{
	this->number = number;
}

void PUSH::Execute()
{
	StackCheck ();
	engine->stack->Push(number);
}

// Signed

PUSHI::PUSHI (int64_t number)
{
	this->number = number;
}

void PUSHI::Execute()
{
	StackCheck ();
	engine->stack->Push(number);
}

// Floating point

PUSHF::PUSHF (double number)
{
	this->number = number;
}

void PUSHF::Execute()
{
	StackCheck ();
	engine->stack->Push(number);
}

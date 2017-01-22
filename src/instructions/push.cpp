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

#include "pop.h"
#include "../engine.h"


POP::POP (Register _register)
{
	this->_register = _register;
}

void POP::Execute()
{
	engine->stack->Pop(_register);
}

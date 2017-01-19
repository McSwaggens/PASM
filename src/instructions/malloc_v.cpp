#include "malloc_v.h"

MALLOC_V::MALLOC_V (Register targetRegister, Register valueRegister)
{
	this->targetRegister = targetRegister;
	this->valueRegister = valueRegister;
}

void MALLOC_V::Execute ()
{
}
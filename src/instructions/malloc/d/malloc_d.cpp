#include "malloc_d.h"

MALLOC_D::MALLOC_D (Register targetRegister, ADDR size)
{
	this->targetRegister = targetRegister;
	this->size = size;
}

void MALLOC_D::Execute ()
{
}
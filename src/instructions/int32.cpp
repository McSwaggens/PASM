#include "int32.h"
#include <iostream>

SET_INT32::SET_INT32 (Register targetRegister, uint32_t number)
{
	this->targetRegister = targetRegister;
	this->number = number;
}

void SET_INT32::Execute ()
{
	std::cout << "Hello Friend" << std::endl;
}
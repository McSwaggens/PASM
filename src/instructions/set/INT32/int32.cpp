#include "int32.h"
#include <iostream>

SET_INT32::SET_INT32 (unsigned int targetRegister, unsigned int number)
{
	this->number = number;
}

void SET_INT32::Execute ()
{
	std::cout << "Hello Friend" << std::endl;
}
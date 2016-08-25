#include "Handler.h"


void Handler::Execute ()
{
}

SET_INT::SET_INT (Register* targetRegister, unsigned int number)
{
	this->targetRegister = targetRegister;
	this->number = number;
}
d
// void SET_INT::Initialize (Register* targetRegister, unsigned int number)
// {
// 	this->targetRegister = targetRegister;
// 	this->number = number;
// }

void SET_INT::Execute ()
{
	std::cout << "Hello World" << std::endl;
}

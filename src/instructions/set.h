#pragma once

#include "../instruction.h"

//[Base SET class]
class SET : public Instruction
{
public:
	Register targetRegister;
	// SET 0 XXX 1 2
	//     ^
	//     - targetRegister
};

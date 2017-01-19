#pragma once

#include "../instruction.h"
#include "../memory.h"

class MALLOC_D : public Instruction
{
private:
	Register targetRegister;
	// MALLOC_D 0x0 123
	//     	    ^
	//          - targetRegister
	
	ADDR size;
	// MALLOC_D 0x0 123
	//				^
	//				- size
	
public:
	MALLOC_D (Register targetRegister, ADDR size);
	virtual void Execute();
};

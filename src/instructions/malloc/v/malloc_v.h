#ifndef __MALLOC_V_H_
#define __MALLOC_V_H_

#include "../../../instruction.h"
#include "../../../memory.h"

class MALLOC_V : public Instruction
{
private:
	Register targetRegister;
	// MALLOC_V 0x0 123
	//     	    ^
	//          - targetRegister
	
	Register valueRegister;
	// MALLOC_V 0x0 0x1
	//				^
	//				- valueRegister
	
public:
	MALLOC_V (Register targetRegister, Register valueRegister);
	virtual void Execute();
};

#endif
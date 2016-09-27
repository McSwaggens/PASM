#ifndef __INSTRUCTION_H_
#define __INSTRUCTION_H_

#include "register.h"

//[Base Handler class]
// Includes our overridable Execute function
class Instruction
{
public:
	virtual void Execute ();
};

#endif
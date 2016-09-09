#pragma once

#ifndef __SET_H_
#define __SET_H_

#include "../../instruction.h"

//[Base SET class]
class SET : public Instruction
{
public:
	unsigned int targetRegister;
	// SET 0 XXX 1 2
	//     ^
	//     - targetRegister
};

#endif
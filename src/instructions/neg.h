#pragma once

#include "../instruction.h"
#include <stdint.h>
#include <stdio.h>

class NEG : public Instruction
{
public:
	virtual void Execute();
};

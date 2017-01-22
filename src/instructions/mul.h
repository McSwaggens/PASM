#pragma once

#include "../instruction.h"
#include <stdint.h>
#include <stdio.h>

class MUL : public Instruction
{
public:
	virtual void Execute();
};

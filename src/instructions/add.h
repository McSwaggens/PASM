#pragma once

#include "../instruction.h"
#include <stdint.h>
#include <stdio.h>

class ADD : public Instruction
{
public:
	virtual void Execute();
};

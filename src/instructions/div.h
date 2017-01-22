#pragma once

#include "../instruction.h"
#include <stdint.h>
#include <stdio.h>

class DIV : public Instruction
{
public:
	virtual void Execute();
};

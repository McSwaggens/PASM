#pragma once

#include "../instruction.h"
#include <stdint.h>
#include <stdio.h>

class POP : public Instruction
{
private:
	Register _register;
public:
	POP (Register _register);
	virtual void Execute();
};

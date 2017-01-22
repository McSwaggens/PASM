#pragma once

#include "../instruction.h"
#include <stdint.h>
#include <stdio.h>

class PUSH : public Instruction
{
private:
	uint64_t number;
public:
	PUSH (uint64_t number);
	virtual void Execute();
};

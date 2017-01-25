#pragma once

#include "../instruction.h"
#include <stdint.h>
#include <stdio.h>

class ADD : public Instruction
{
public:
	virtual void Execute();
};

class ADDI : public Instruction
{
public:
	virtual void Execute();
};

class ADDF : public Instruction
{
public:
	virtual void Execute();
};

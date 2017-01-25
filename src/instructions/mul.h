#pragma once

#include "../instruction.h"
#include <stdint.h>
#include <stdio.h>

class MUL : public Instruction
{
public:
	virtual void Execute();
};

class MULI : public Instruction
{
public:
	virtual void Execute();
};

class MULF : public Instruction
{
public:
	virtual void Execute();
};

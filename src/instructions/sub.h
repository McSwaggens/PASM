#pragma once

#include "../instruction.h"
#include <stdint.h>
#include <stdio.h>

class SUB : public Instruction
{
public:
	virtual void Execute();
};

class SUBI : public Instruction
{
public:
	virtual void Execute();
};

class SUBF : public Instruction
{
public:
	virtual void Execute();
};

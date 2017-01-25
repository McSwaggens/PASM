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

class PUSHI : public Instruction
{
private:
	int64_t number;
public:
	PUSHI (int64_t number);
	virtual void Execute();
};

class PUSHF : public Instruction
{
private:
	double number;
public:
	PUSHF (double number);
	virtual void Execute();
};

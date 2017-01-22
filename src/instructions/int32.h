#pragma once

#include "set.h"

class SET_INT32 : public SET
{
private:
	unsigned int number;
public:
	SET_INT32 (Register targetRegister, unsigned int number);
	virtual void Execute();
};
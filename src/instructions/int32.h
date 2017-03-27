#pragma once

#include "set.h"

class SET_INT32 : public SET
{
private:
	uint32_t number;
public:
	SET_INT32 (Register targetRegister, uint32_t number);
	virtual void Execute();
};

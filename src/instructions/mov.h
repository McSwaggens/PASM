#pragma once

#include "../instruction.h"

class MOV : public Instruction
{
private:
	uint32_t point_id;
	
public:
	MOV (uint32_t point_id);
	virtual void Execute();
};

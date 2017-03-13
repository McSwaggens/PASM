#pragma once

#include "../instruction.h"
#include <vector>

struct PointPair
{
	uint32_t line;
	uint32_t point_id;
	
	PointPair (uint32_t _line, uint32_t _point_id);
};

extern std::vector<PointPair> points;

uint32_t GetPoint (uint32_t _id);

class PT : public Instruction
{
private:
	uint32_t id;
	
public:
	PT (uint32_t _id);
	virtual void Execute();
};

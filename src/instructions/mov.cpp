#include "mov.h"
#include "../engine.h"

MOV::MOV (uint32_t point_id)
{
	this->point_id = point_id;
}

void MOV::Execute ()
{
	uint32_t line = GetPoint(point_id);
	engine->SetLine (line);
}
#include "pt.h"
#include "../engine.h"

// Point pair

std::vector<PointPair> points;

PointPair::PointPair (uint32_t _line, uint32_t _point_id)
{
	this->line = _line;
	this->point_id = _point_id;
}

uint32_t GetPoint (uint32_t _id)
{
	for (size_t i = 0; i < points.size(); i++)
	{
		if (points[i].point_id == _id)
			return points[i].line;
	}
}

//

PT::PT (uint32_t _id, uint32_t current_line)
{
	this->id = _id;
	points.push_back (PointPair (current_line, _id));
}

void PT::Execute ()
{
	// No execution code
	// .. maybe skip a line to continue 1 line of execution ... ?
}
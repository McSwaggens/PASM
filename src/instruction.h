#pragma once

#include "register.h"

//[Base Handler class]
// Includes our overridable Execute function
class Instruction
{
public:
	virtual void Execute ();
};

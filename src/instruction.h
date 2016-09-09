#pragma once

#ifndef __HANDLER_H_
#define __HANDLER_H_

#include "register.h"

//[Base Handler class]
// Includes our overridable Execute function
class Instruction
{
public:
	virtual void Execute ();
};

#endif
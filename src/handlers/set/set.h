#pragma once

#ifndef __SET_H_
#define __SET_H_

#include "../../handler.h"

//[Base SET class]
class SET : public Handler
{
public:
	unsigned int targetRegister;
	// SET 0 XXX 1 2
	//     ^
	//     - targetRegister
};

#endif
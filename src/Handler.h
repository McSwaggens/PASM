#pragma once
// <iostream> for debugging code
// Comment if NOT needed
#include <iostream>
#include "Register.h"

//[Base Handler class]
// Includes our overridable Execute function
class Handler
{
public:
	virtual void Execute ();
};

//[Base SET class]
class SET : public Handler
{
public:
	Register* targetRegister;
	// SET 0 XXX 1 2
	//     ^
	//     - targetRegister
};

class SET_INT : public SET
{
private:
	unsigned int number;
public:
	SET_INT (Register* targetRegister, unsigned int number);
	// void Initialize (Register* targetRegister, unsigned int number);
	virtual void Execute();
};

#ifndef __ENGINE_H_
#define __ENGINE_H_

class Engine;

#include <iostream>
#include <string>
#include <vector>
#include "memory.h"
#include "instruction.h"
#include "parser.h"
#include "globaldefines.h"
#include "stack.h"

#define MAX_REGISTER_STACK_SIZE 255

class Engine
{
private:
// Member variables
	std::vector<Instruction*> instructions;
	unsigned int line = 0;
	
	Stack*		stack			= new Stack();
	ADDR*		registerStack	= new ADDR[MAX_REGISTER_STACK_SIZE];

// Member functions
	bool	CheckRAM (); // Check if the ram module is initialized
public:
// Constructor
	Engine ();
	
// Member variables
	Memory*	ram;
	
// Member functions
	void	Load (std::string code);
	void	Execute (int lines);
	void	InitializeRAM (unsigned long size);
	void	InitializeRAM (Memory* memory);
};

#endif
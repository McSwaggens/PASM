#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "memory.h"
#include "instruction.h"
#include "parser.h"
#include "globaldefines.h"
#include "stack.h"
#include "error.h"

#define MAX_REGISTER_STACK_SIZE 255

class Engine;

extern Engine* engine;

class Engine
{
private:
// Member variables
	std::vector<Instruction*> instructions;
	uint32_t line = 0;
	bool running = false;

// Member functions
	bool	CheckRAM (); // Check if the ram module is initialized
public:
// Constructor
	Engine ();
	
// Member variables
	Memory*		memory;
	Stack*		stack			= new Stack();
	ADDR*		registerStack	= new ADDR[MAX_REGISTER_STACK_SIZE];
	
// Member functions
	void	Load (std::string code);
	void	Execute ();
	void	Execute (int lines);
	void	InitializeRAM (unsigned long size);
	void	InitializeRAM (Memory* memory);
	void	SetLine (uint32_t line);
	void	StopEngineExecution ();
	size_t		GetInstructionsSize ();
	uint32_t	GetLineNumber ();
};

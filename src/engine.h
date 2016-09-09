#include <iostream>
#include <string>
#include <vector>
#include "string.h"
#include "memory.h"
#include "instruction.h"
#include "parser.h"
#include "globaldefines.h"


class Engine
{
private:
	std::vector<Instruction*> instructions;
	unsigned int line = 0;
	
	bool CheckRAM (); // Check if the ram module is initialized
public:
// Constructor
	Engine();
	
// Member variables
	Memory* ram;
	
// Member functions
	void Load (std::string code);
	void Execute (int lines);
	void InitializeRAM (unsigned long size);
	void InitializeRAM (Memory* memory);
};
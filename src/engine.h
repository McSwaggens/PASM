#include <iostream>
#include <string>
#include <vector>
#include "string.h"
#include "memory.h"
#include "handler.h"
#include "parser.h"
#include "globaldefines.h"

#include "handlers/set/INT32/int32.h"

class Engine
{
private:
	std::vector<Handler*> code;
	
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
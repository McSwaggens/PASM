#include <iostream>
#include <stdio.h>
#include <string>
#include "string.h"
#include <vector>
#include "memory.h"
#include "handler.h"
#include "parser.h"
#include "globaldefines.h"

using namespace std;

class Engine
{
private:
	Handler* code;
	
	bool CheckRAM (); // Check if the ram module is initialized
public:
// Constructor
	Engine();
	
// Member variables
	Memory* ram;
	
// Member functions
	void Load (string code);
	void Execute (int lines);
	void InitializeRAM (unsigned long size);
	void InitializeRAM (Memory* memory);
};
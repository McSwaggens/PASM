#pragma once

#include <iostream>
#include <string>
#include "string.h"
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "instructions/set/INT32/int32.h"
#include "instructions/malloc/d/malloc_d.h"

namespace Parser
{
	std::vector<std::string> SeperateLines (std::string* code);
	std::vector<std::string> SeperateSpaces (std::string* line);
	
	Instruction* GetInstruction (std::vector<std::string> parts);
	
}

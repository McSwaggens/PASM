#pragma once

#include <iostream>
#include <string>
#include "string.h"
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "instructions/int32.h"
#include "instructions/malloc_d.h"
#include "instructions/push.h"
#include "instructions/add.h"
#include "instructions/sub.h"
#include "instructions/div.h"
#include "instructions/mul.h"
#include "instructions/pop.h"
#include "instructions/pt.h"

namespace Parser
{
	std::vector<std::string> SeperateLines (std::string* code);
	std::vector<std::string> SeperateSpaces (std::string* line);
	
	Instruction* GetInstruction (std::vector<std::string> parts);
	
}

#pragma once

#include <iostream>
#include <string>
#include "string.h"
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "handlers/set/INT32/int32.h"

namespace Parser
{
	std::vector<std::string> SeperateLines (std::string* code);
	std::vector<std::string> SeperateSpaces (std::string* line);
	
	Handler* GetHandler (std::vector<std::string> parts);
	
}
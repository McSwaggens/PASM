#include <iostream>
#include <string>
#include "string.h"
#include <vector>
#include <algorithm>

#pragma once

namespace Parser
{
	std::vector<std::string> SeperateLines (std::string* code);
	std::vector<std::string> SeperateSpaces (std::string* line);
}
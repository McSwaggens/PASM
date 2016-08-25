#include "Engine.h"

Engine::Engine ()
{
}

void Engine::Initialize ()
{
}

void Engine::Execute (int lines)
{
}

void Engine::Load (string code)
{
	long codeLength = code.length();
	
	if (SHOW_DEBUG_INFORMATION)
	{
		std::cout << codeLength << " characters being loaded into engine" << std::endl;
	}
	
	// Get all lines out of the single string
	std::vector<std::string> lines = Parser::SeperateLines (&code);
	
	if (SHOW_DEBUG_INFORMATION) // Print the amount of lines returned from the Parser
	{
		std::cout << "Parser::SeperateLines returned " << lines.size() << " lines" << std::endl;
	}
	
	for (long ln = 0; ln < lines.size(); ln++)
	{
		string currentLine = lines[ln];
		std::vector<std::string> parts = Parser::SeperateSpaces (&currentLine);
		
		if (SHOW_DEBUG_INFORMATION) // print all string parts
		{
			for (int i = 0; i < parts.size(); i++)
			{
				std::cout << parts[i] << std::endl;
			}
		}
		
		// Convert line into Handler objects
		this->code = new Handler[lines.size()];
		
		//Handler* handler = new SET_INT ();
		//handler->Execute ();
		
	}
}
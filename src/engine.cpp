#include "engine.h"

Engine::Engine ()
{
}

void Engine::InitializeRAM (unsigned long size)
{
	// Check if the current ram module is already initialized
	if (this->ram != NULL)
	{
		// Delete the ram module
		delete this->ram;
	}
	
	// Set the new ram module with a given size
	this->ram = new Memory (size);
}

void Engine::InitializeRAM (Memory* memory)
{
	// Check if the current ram module is already initialized
	if (this->ram != NULL)
	{
		// Delete the ram module
		delete this->ram;
	}
	
	// Set the ram module to already existing module
	this->ram = memory;
}

void Engine::Execute (int lines)
{
	// Check if the ram module is initialize or not
	// Engine should refuse the execute without a memory (ram) module initialized
	if (!this->CheckRAM())
	{	// Memory module has NOT been initialized
		// Throw an error
		std::cout 	<< "Cannot execute engine without a valid memory module initialized"
					<< std::endl;
		return;
	}
	else // Memory module HAS been initialized correctly
	{
		for (auto instruction : instructions)
		{
			instruction->Execute ();
		}
	}
}

// Check if the ram module has been initialized
bool Engine::CheckRAM ()
{
	if (this->ram == NULL) // Check if the pointer of the ram module is NULL
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Engine::Load (std::string instructions)
{
	long instructionsLength = instructions.length();
	
	if (SHOW_DEBUG_INFORMATION)
	{
		std::cout << instructionsLength << " characters being loaded into engine" << std::endl;
	}
	
	// Get all lines out of the single string
	std::vector<std::string> lines = Parser::SeperateLines (&instructions);
	
	if (SHOW_DEBUG_INFORMATION) // Print the amount of lines returned from the Parser
	{
		std::cout << "Parser::SeperateLines returned " << lines.size() << " lines" << std::endl;
	}
	
	this->instructions.resize (lines.size());
		
	for (long ln = 0; ln < lines.size(); ln++)
	{
		std::string currentLine = lines[ln];
		std::vector<std::string> parts = Parser::SeperateSpaces (&currentLine);
		
		if (SHOW_DEBUG_INFORMATION) // print all string parts
		{
			for (int i = 0; i < parts.size(); i++)
			{
				std::cout << parts[i] << std::endl;
			}
		}
	}
}
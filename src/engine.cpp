#include "engine.h"

Engine::Engine ()
{
	engine = this;
}

void Engine::InitializeRAM (uint64_t size)
{
	// Check if the current ram module is already initialized
	if (this->memory)
	{
		// Delete the ram module
		delete this->memory;
	}
	
	// Set the new ram module with a given size
	this->memory = new Memory (size);
}

void Engine::InitializeRAM (Memory* memory)
{
	// Check if the current ram module is already initialized
	if (this->memory)
	{
		// Delete the ram module
		delete this->memory;
	}
	
	// Set the ram module to already existing module
	this->memory = memory;
}

void Engine::Execute ()
{
	running = true;
	
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
		for (;this->line < instructions.size () && running; this->line++)
		{
			Instruction* instruction = this->instructions[this->line];
			instruction->Execute ();
		}
	}
	
	running = false;
}

void Engine::Execute (int lines)
{
	running = true;
	
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
		for (int i = 0; i < lines && this->line < instructions.size () && running; i++, this->line++)
		{
			Instruction* instruction = this->instructions[this->line];
			instruction->Execute ();
		}
	}
	
	running = false;
}

// Check if the ram module has been initialized
bool Engine::CheckRAM ()
{
	return this->memory;
}

void Engine::Load (std::string instructions)
{
	size_t instructionsLength = instructions.length();

#if SHOW_DEBUG_INFORMATION
		std::cout << instructionsLength << " characters being loaded into engine" << std::endl;
#endif

	// Get all lines out of the single string
	std::vector<std::string> lines = Parser::SeperateLines (&instructions);

#if SHOW_DEBUG_INFORMATION
		std::cout << "Parser::SeperateLines returned " << lines.size() << " lines" << std::endl;
#endif

	this->instructions.resize (lines.size());

	for (size_t ln = 0; ln < lines.size(); ln++)
	{
		std::string currentLine = lines[ln];
		std::vector<std::string> parts = Parser::SeperateSpaces (&currentLine);

#if SHOW_DEBUG_INFORMATION
		for (int i = 0; i < parts.size(); i++)
		{
			std::cout << parts[i] << std::endl;
		}
#endif
		
		Instruction* instruction = Parser::GetInstruction (parts, ln);
		this->instructions[ln] = instruction;
	}
}

size_t Engine::GetInstructionsSize ()
{
	return instructions.size ();
}

void Engine::SetLine (uint32_t line)
{
	this->line = line;
}

uint32_t Engine::GetLineNumber ()
{
	return this->line;
}

void Engine::StopEngineExecution ()
{
	this->running = false;
}

#include "program.h"

int main ()
{
	if (SHOW_DEBUG_INFORMATION)
	{
		std::cout << "Script location: " << DEFAULT_SCRIPT_LOCATION << std::endl;
	}
	
	std::string script = LoadScript ();
	
	if (SHOW_DEBUG_INFORMATION)
	{
		std::cout << "-----[Script]-----" << std::endl;
		std::printf(script.c_str());
		std::cout << "-----[Script]-----" << std::endl;
	}
	
	// Create an instance of the engine
	engine = new Engine();
	
	// Load the script into the engine
	engine->Load(script);
	
	// Start the engine
	Run();
}

std::string LoadScript ()
{
	std::ifstream file(DEFAULT_SCRIPT_LOCATION);
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	return content;
}

void Run ()
{
	while (true)
	{
		engine->Execute(1);
	}
}

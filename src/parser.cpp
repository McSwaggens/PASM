#include "parser.h"
#include "memory.h"

std::vector<std::string> Parser::SeperateLines (std::string* code)
{
	// Get the length of the entire string
	long length = code->length();
	
	// Initialize our char array with a buffer
	char charr[length];
	
	// Copy all of the chars inside of the string (code) into the charr buffer 
	strcpy (charr, code->c_str());
	
	// List for out lines to be stored
	std::vector<std::string> lines;
	
	std::string currentLine;
	
	// Loop through all of the characters in the code string
	for (long i = 0; i < length; i++)
	{
		char c = charr[i];
		
		if (c == '\n') // End of a single line
		{
			// Add the current line of characters into the list
			if (currentLine != "")
			{
				lines.push_back (currentLine);
			}
			
			// Clear the currentLine string to be re-used
			currentLine = "";
		}
		else // Just a normal character
		{
			// Add the current character (c) into the currentLine string
			currentLine += c;
		}
	}
	
	return lines;
}

std::vector<std::string> Parser::SeperateSpaces (std::string* line)
{
	// Get the total length of the string
	int length = line->length();
	
	// Create a character array buffer
	char charr[line->length()];
	
	// Copy the characters from the string into the buffer
	strcpy (charr, line->c_str());
	
	std::vector<std::string> parts;
	
	std::string current;
	
	for (int i = 0; i < length; i++)
	{
		char c = charr[i];
		
		if (c == ' ') // Character c is a space
		{
			parts.push_back (current);
			current = "";
		}
		else // Normal character
		{
			current += c;
		}
	}
	
	// Add the last element to the parts
	if (current != "")
		parts.push_back (current);
	
	return parts;
}

bool IsNumber (std::string const& s, unsigned int& number)
{
	if (s.find_first_not_of("0123456789", 0) == std::string::npos)
	{
		number = std::atoi (s.c_str());
		return true;
	}
	return false;
}

bool IsHex_0x (std::string const& str)
{
	return str.compare(0, 2, "0x") == 0
		&& str.size() > 2
		&& str.find_first_not_of("0123456789abcdefABCDEF", 2) == std::string::npos;
}

bool IsHex (std::string const& str)
{
	return str.find_first_not_of("0123456789abcdefABCDEF", 0) == std::string::npos;
}

bool IsRegister (std::string str, Register& _register)
{
	
	_register.isPrivate = str[0] == ':';
	
	char c_num[_register.isPrivate ? str.size() : str.size()-1];
	
	for (int i = 1; i < str.size (); i++)
	{
		char cur_c = str[i];
		c_num[i-1] = cur_c;
	}
	
	if (IsHex (c_num))
	{
		unsigned short int hex;
		hex = std::strtol (c_num, NULL, 16);
		_register.id = hex;
	}
	else
	{
		std::cout << str << " NOT HEX " << std::endl;
		return false;
	}
	
	return true;
}

Instruction GetSetInstruction (Register targetRegister, std::vector<std::string> parts)
{
	if (parts[2] == "INT32")
	{
		unsigned int number;
		if (IsNumber (parts[3], number))
		{
			return SET_INT32 (targetRegister, number);
		}
	}
	throw 0;
}

Instruction Parser::GetInstruction (std::vector<std::string> parts)
{
	
	/*---- Stack ----*/
	if (parts[0] == "push")
	{
	}
	else if (parts[0] == "pop")
	{
	}
	else if (parts[0] == "add")
	{
	}
	else if (parts[0] == "neg")
	{
	}
	else if (parts[0] == "mul")
	{
	}
	else if (parts[0] == "div")
	{
	}
	/*---- Normal ----*/
	else if (parts[0] == "set")
	{
		Register _register;
		if (IsRegister (parts[1], _register))
		{
			return GetSetInstruction (_register, parts);
		}
		else
		{
			printf ("SYNTAX ERROR: EXPECTED REGISTER AFTER SET INSTRUCTION [SET]!\n");
			throw 0;
		}
	}
	else if (parts[0] == "mov")
	{
	}
	else if (parts[0] == "call")
	{
	}
	else if (parts[0] == "malloc_v")
	{
	}
	else if (parts[0] == "malloc_d")
	{
		Register targetRegister;
		if (IsRegister (parts[1], targetRegister))
		{
			unsigned int size;
			if (IsNumber (parts[2], size))
			{
				MALLOC_D malloc_d (targetRegister, size);
				return malloc_d;
			}
			else
			{
				printf ("SYNTAX ERROR: EXPECTED NUMBER AFTER REGISTER [MALLOC_D]!\n");
				throw 0;
			}
		}
		else
		{
			printf ("SYNTAX ERROR: EXPECTED REGISTER AFTER SET INSTRUCTION [MALLOC_D]!\n");
			throw 0;
		}
	}
	else if (parts[0] == "free")
	{
	}
	else if (parts[0] == "ret")
	{
	}
	else if (parts[0] == "copy")
	{
	}
	throw 123;
}

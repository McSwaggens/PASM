#include "parser.h"

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

bool IsNumber (std::string const& s)
{
	return s.find_first_not_of("0123456789", 0) == std::string::npos;
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

bool IsRegister (std::string* strn, Register* reg)
{
	const char* str = &strn->c_str()[0];
	
	Register _register;
	
	_register.isPrivate = str[0] == ':';
	
	char c_num[_register.isPrivate ? sizeof(str) : sizeof(str)-1];
	
	for (int i = 1; i < sizeof (str); i++)
	{
		char cur_c = str[0];
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
		return false;
	}
	
	*reg = _register;
	return true;
}

Handler* Parser::GetHandler (std::vector<std::string> parts)
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
	else if (parts[0] == "mov")
	{
	}
	else if (parts[0] == "call")
	{
	}
	else if (parts[0] == "malloc")
	{
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



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
	if (currentLine != "")
		lines.push_back(currentLine);
	
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

bool IsNumber (std::string const& s, uint64_t& number)
{
	if (s.find_first_not_of("0123456789", 0) == std::string::npos)
	{
		number = std::atol(s.c_str());
		return true;
	}
	return false;
}

bool IsNumberFloat (std::string const& s, double& number)
{
	if (s.find_first_not_of("0123456789.", 0) == std::string::npos)
	{
		number = std::stof(s.c_str());
		return true;
	}
	return false;
}

bool IsHex_0x (std::string const& str, uint64_t& number)
{
	if (str.compare(0, 2, "0x") == 0
		&& str.size() > 2
		&& str.find_first_not_of("0123456789abcdefABCDEF", 2) == std::string::npos)
	{
		number = strtol(str.c_str(), nullptr, 16);
		
		return true;
	}
	
	return false;
}

bool IsHex (std::string const& str, uint64_t& number)
{
	if (str.find_first_not_of("0123456789abcdefABCDEF", 0) == std::string::npos)
	{
		number = strtol(str.c_str(), nullptr, 16);
		return true;
	}
	
	return false;
}

bool IsHex (std::string const& str)
{
	return str.find_first_not_of("0123456789abcdefABCDEF", 0) == std::string::npos;
}

bool IsRegister (std::string str, Register& _register)
{
	_register.is_private = str[0] == ':';
	
	const char* c_num = _register.is_private ? &str[1] : str.c_str();
	
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

Instruction* GetSetInstruction (Register targetRegister, std::vector<std::string> parts)
{
	if (parts[2] == "INT32")
	{
		uint64_t number;
		if (IsNumber (parts[3], number))
		{
			return new SET_INT32 (targetRegister, number);
		}
	}
	throw 0;
}

Instruction* Parser::GetInstruction (std::vector<std::string> parts, unsigned int current_line)
{
	
	/*---- Stack ----*/
	if (parts[0] == "push")
	{
		uint64_t number;
		if (IsNumber (parts[1], number))
		{
			PUSH* push = new PUSH(number);
			return push;
		}
	}
	if (parts[0] == "pushi")
	{
		uint64_t number;
		if (IsNumber (parts[1], number))
		{
			PUSH* push = new PUSH(number);
			return push;
		}
	}
	if (parts[0] == "pushf")
	{
		double number;
		if (IsNumberFloat (parts[1], number))
		{
			PUSHF* push = new PUSHF(number);
			return push;
		}
	}
	else if (parts[0] == "pop")
	{
		Register _register;
		if (IsRegister (parts[1], _register))
		{
			POP* pop = new POP(_register);
			return pop;
		}
		else
		{
			printf("[ERROR]: expected register as second parameter. [pop]");
		}
	}
	else if (parts[0] == "add")
	{
		ADD* add = new ADD;
		return add;
	}
	else if (parts[0] == "sub")
	{
		SUB* sub = new SUB;
		return sub;
	}
	else if (parts[0] == "mul")
	{
		MUL* mul = new MUL;
		return mul;
	}
	else if (parts[0] == "div")
	{
		DIV* div = new DIV;
		return div;
	}
	else if (parts[0] == "addi")
	{
		ADDI* add = new ADDI;
		return add;
	}
	else if (parts[0] == "subi")
	{
		SUBI* sub = new SUBI;
		return sub;
	}
	else if (parts[0] == "muli")
	{
		MULI* mul = new MULI;
		return mul;
	}
	else if (parts[0] == "divi")
	{
		DIVI* div = new DIVI;
		return div;
	}
	else if (parts[0] == "addf")
	{
		ADDF* add = new ADDF;
		return add;
	}
	else if (parts[0] == "subf")
	{
		SUBF* sub = new SUBF;
		return sub;
	}
	else if (parts[0] == "mulf")
	{
		MULF* mul = new MULF;
		return mul;
	}
	else if (parts[0] == "divf")
	{
		DIVF* div = new DIVF;
		return div;
	}
	/*---- Normal ----*/
	else if (parts[0] == "setf")
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
	else if (parts[0] == "pt")
	{
		uint64_t id;
		if (IsHex(parts[1], id))
		{
			PT* pt = new PT (id, current_line);
			return pt;
		}
		else
		{
			printf ("SYNTAX ERROR: EXPECTED HEX NUMBER AFTER PT INSTRUCTION [PT]!\n");
			throw 0;
		}
	}
	else if (parts[0] == "mov")
	{
		uint64_t point_id;
		if (IsHex (parts[1], point_id))
		{
			MOV* mov = new MOV (point_id);
			printf ("Added mov instruction!\n");
			return mov;
		}
		else
		{
			printf ("SYNTAX ERROR: EXPECTED HEX NUMBER AFTER MOV INSTRUCTION [MOV]!\n");
			throw 0;
		}
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
			uint64_t size;
			if (IsNumber (parts[2], size))
			{
				MALLOC_D* malloc_d = new MALLOC_D (targetRegister, size);
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
	printf("Unknown instruction: %s\n", parts[0].c_str());
	
	return nullptr;
}

#include "Parser.h"

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
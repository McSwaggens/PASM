#include "error.h"

#include <stdio.h>
#include "engine.h"

Error::Error ()
{
}

Error::Error (char* name, char* description)
{
	this->name = name;
	this->description = description;
}

void ThrowError (Error error, char* additional_information)
{
	printf ("! ERROR\n! %s on line %i\n! Description: %s\n! Additional information: %s\n", error.name, engine->GetLineNumber (), error.description, additional_information ? additional_information : "NONE");
	engine->StopEngineExecution ();
}

#define ED const Error

ED STACK_OVERFLOW ("Stack Overflow", "An attempt to push a value into a full stack.");
ED STACK_UNDERFLOW ("Stack Underflow", "Either there are no elements in the stack or the required amount of elements in the stack is not met by the current operation.");

#undef ED

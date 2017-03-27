#pragma once

#include <stdint.h>

struct Error
{
	char* name;
	char* description;
	
	Error ();
	Error (char* name, char* description);
};

void ThrowError (Error error, char* additional_information = nullptr);

#define _ERROR(a,b) ThrowError(a,b);return;
#define ERROR(a) ThrowError(a);return;

extern const Error STACK_OVERFLOW;
extern const Error STACK_UNDERFLOW;

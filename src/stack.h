#pragma once

#include "register.h"
#include <stdint.h>
#include <stdio.h>


#define MAX_SIZE 255
#define MAX_BYTES 8

class Stack
{
private:
	char stack[MAX_SIZE][MAX_BYTES];
	char position;
	
	bool IsStackOpen ();
	
public:
	
	Stack ();
	
	void Print (uint8_t size = MAX_SIZE);
	
	/*---- INT ----*/
	
	void Push (uint8_t value);
	void Push (uint16_t value);
	void Push (uint32_t value);
	void Push (uint64_t value);
	
	/*---- FLOAT ----*/
	
	void Push (float value);
	void Push (double value);
	
	/*----  Mathematics ----*/
	
	void Add ();
	void Sub ();
	void Mul ();
	void Div ();
	
	/*---- POP ----*/
	
	void Pop (Register reg);
};

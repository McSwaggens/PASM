#pragma once

#include "register.h"
#include <stdint.h>
#include <stdio.h>


#define MAX_SIZE 255
#define MAX_BYTES 8

class Stack
{
private:
	uint8_t stack[MAX_SIZE][MAX_BYTES];
	uint8_t position;
	
	bool IsStackOpen ();
	
public:
	
	Stack ();
	
	uint8_t GetPosition ();
	
	void Print (uint8_t size = MAX_SIZE);
	void PrintFl (uint8_t size = MAX_SIZE);
	
	/*---- INT ----*/
	
	void Push (uint8_t value);
	void Push (uint16_t value);
	void Push (uint32_t value);
	void Push (uint64_t value);
	
	void Push (int64_t value);
	
	/*---- FLOAT ----*/
	
	void Push (float value);
	void Push (double value);
	
	/*----  Mathematics ----*/
	
	// Default unsigned
	void Add ();
	void Sub ();
	void Mul ();
	void Div ();
	
	
	// Signed
	void Add_i ();
	void Sub_i ();
	void Mul_i ();
	void Div_i ();
	
	
	// floating point
	void Add_f ();
	void Sub_f ();
	void Mul_f ();
	void Div_f ();
	
	/*---- POP ----*/
	
	void Pop (Register reg);
};

#pragma once

#include "register.h"
#include <stdint.h>
#include <stdio.h>


#define MAX_SIZE 255
#define MAX_BYTES 8

struct Stack
{
private:
	char stack[MAX_SIZE][MAX_BYTES];
	char position;
	
	bool IsStackOpen ()
	{
		return position != MAX_SIZE;
	}
	
public:
	
	Stack ()
	{
		for (int x = 0; x < MAX_SIZE; x++)
		{
			for (int y = 0; y < MAX_BYTES; y++)
			{
				stack[x][y] = 0;
			}
		}
	}
	
	void Print (uint8_t size = MAX_SIZE)
	{
		printf("stack pos: %i\n", position);
		for (uint8_t i = 0; i < size; i++)
		{
			uint64_t number = *(uint64_t*)&stack[i];
			
			printf ("[%i]:\t%lu\n", i, number);
		}
	}
	
	/*---- INT ----*/
	
	void Push (uint8_t value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<uint64_t*>(stack[position]) = (uint64_t)value;
		position++;
	}
	
	void Push (uint16_t value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<uint64_t*>(stack[position]) = (uint64_t)value;
		position++;
	}
	
	void Push (uint32_t value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<uint64_t*>(stack[position]) = (uint64_t)value;
		position++;
	}
	
	void Push (uint64_t value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<uint64_t*>(stack[position]) = value;
		position++;
	}
	
	/*---- FLOAT ----*/
	
	void Push (float value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<long*>(stack[position]) = (double)value;
		position++;
	}
	
	void Push (double value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<long*>(stack[position]) = value;
		position++;
	}
	
	/*----  Mathematics ----*/
	
	void Add ()
	{
		position--;
		uint64_t number_value_1 = *(uint64_t*)&stack[position][0];
		uint64_t number_value_2 = *(uint64_t*)&stack[position-1][0];
		
		
		uint64_t newValue = number_value_2 + number_value_1;
		*reinterpret_cast<uint64_t*>(stack[position-1]) = newValue;
		*reinterpret_cast<uint64_t*>(stack[position]) = 0;
	}
	
	void Sub ()
	{
		position--;
		uint64_t number_value_1 = *(uint64_t*)&stack[position][0];
		uint64_t number_value_2 = *(uint64_t*)&stack[position-1][0];
		
		
		uint64_t newValue = number_value_2 - number_value_1;
		*reinterpret_cast<uint64_t*>(stack[position-1]) = newValue;
		*reinterpret_cast<uint64_t*>(stack[position]) = 0;
	}
	
	void Mul ()
	{
		position--;
		uint64_t number_value_1 = *(uint64_t*)&stack[position][0];
		uint64_t number_value_2 = *(uint64_t*)&stack[position-1][0];
		
		
		uint64_t newValue = number_value_2 * number_value_1;
		*reinterpret_cast<uint64_t*>(stack[position-1]) = newValue;
		*reinterpret_cast<uint64_t*>(stack[position]) = 0;
	}
	
	void Div ()
	{
		position--;
		uint64_t number_value_1 = *(uint64_t*)&stack[position][0];
		uint64_t number_value_2 = *(uint64_t*)&stack[position-1][0];
		
		
		uint64_t newValue = number_value_2 / number_value_1;
		*reinterpret_cast<uint64_t*>(stack[position-1]) = newValue;
		*reinterpret_cast<uint64_t*>(stack[position]) = 0;
	}
	
	/*---- POP ----*/
	
	void Pop (Register* reg)
	{
		//TODO: Pop the value into the Registers ram address
	}
};

#pragma once

#include "register.h"
#include <stdint.h>


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
	
	/*---- INT ----*/
	
	void Push (uint8_t value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<long*>(stack[position]) = (long)value;
		position++;
	}
	
	void Push (uint16_t value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<long*>(stack[position]) = (long)value;
		position++;
	}
	
	void Push (uint32_t value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<long*>(stack[position]) = (long)value;
		position++;
	}
	
	void Push (uint64_t value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<long*>(stack[position]) = value;
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
	
	/*----  Mathamatics ----*/
	
	void Add ()
	{
		position--;
		uint64_t number_value_1 = *(uint64_t *)&stack[position][0];
		uint64_t number_value_2 = *(uint64_t *)&stack[position-1][0];
		
		
		long newValue = number_value_1 + number_value_2;
		*reinterpret_cast<long*>(stack[position]) = newValue;
		position++;
	}
	
	void Sub ()
	{
		position--;
		uint64_t number_value_1 = *(uint64_t *)&stack[position][0];
		uint64_t number_value_2 = *(uint64_t *)&stack[position-1][0];
		
		
		long newValue = number_value_1 - number_value_2;
		*reinterpret_cast<long*>(stack[position]) = newValue;
		position++;
	}
	
	void Mul ()
	{
		position--;
		uint64_t number_value_1 = *(uint64_t *)&stack[position][0];
		uint64_t number_value_2 = *(uint64_t *)&stack[position-1][0];
		
		
		long newValue = number_value_1 / number_value_2;
		*reinterpret_cast<long*>(stack[position]) = newValue;
		position++;
	}
	
	void Div ()
	{
		position--;
		uint64_t number_value_1 = *(uint64_t *)&stack[position][0];
		uint64_t number_value_2 = *(uint64_t *)&stack[position-1][0];
		
		
		long newValue = number_value_1 / number_value_2;
		*reinterpret_cast<long*>(stack[position]) = newValue;
		position++;
	}
	
	/*---- POP ----*/
	
	void Pop (Register* reg)
	{
		//TODO: Pop the value into the Registers ram address
	}
};

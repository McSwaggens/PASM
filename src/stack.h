#ifndef __STACK_H_
#define __STACK_H_

#include "register.h"

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
	
	/*---- INT ----*/
	
	void Push (char value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<long*>(stack[position]) = (long)value;
		position++;
	}
	
	void Push (short value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<long*>(stack[position]) = (long)value;
		position++;
	}
	
	void Push (int value)
	{
		if (!IsStackOpen()) return;
		*reinterpret_cast<long*>(stack[position]) = (long)value;
		position++;
	}
	
	void Push (long value)
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
		long number_value_1 = *(long *)&stack[position][0];
		long number_value_2 = *(long *)&stack[--position][0];
		
		
		long newValue = number_value_1 + number_value_2;
		*reinterpret_cast<long*>(stackp[position]) = newValue;
	}
	
	/*---- POP ----*/
	
	void Pop (Register* reg)
	{
		//TODO: Pop the value into the Registers ram address
	}
};

#endif

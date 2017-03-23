#include "stack.h"
#include "engine.h"


Stack::Stack ()
{
	for (int x = 0; x < MAX_SIZE; x++)
	{
		for (int y = 0; y < MAX_BYTES; y++)
		{
			stack[x][y] = 0;
		}
	}
}

unsigned char Stack::GetPosition ()
{
	return this->position;
}

bool Stack::IsStackOpen ()
{
	return position != MAX_SIZE;
}

void Stack::Print (uint8_t size)
{
	printf("stack pos: %i\n", position);
	for (uint8_t i = 0; i < size; i++)
	{
		uint64_t number = *(uint64_t*)&stack[i];
		
		printf ("[%i]:\t%lu\n", i, number);
	}
}

void Stack::PrintFl (uint8_t size)
{
	printf("stack pos: %i\n", position);
	for (uint8_t i = 0; i < size; i++)
	{
		double number = *(double*)&stack[i];
		
		printf ("[%i]:\t%f\n", i, number);
	}
}

/*---- INT ----*/

void Stack::Push (uint8_t value)
{
	if (!IsStackOpen()) return;
	*reinterpret_cast<uint64_t*>(stack[position]) = (uint64_t)value;
	position++;
}

void Stack::Push (uint16_t value)
{
	if (!IsStackOpen()) return;
	*reinterpret_cast<uint64_t*>(stack[position]) = (uint64_t)value;
	position++;
}

void Stack::Push (uint32_t value)
{
	if (!IsStackOpen()) return;
	*reinterpret_cast<uint64_t*>(stack[position]) = (uint64_t)value;
	position++;
}

void Stack::Push (uint64_t value)
{
	if (!IsStackOpen()) return;
	*reinterpret_cast<uint64_t*>(stack[position]) = value;
	position++;
}

void Stack::Push (int64_t value)
{
	if (!IsStackOpen()) return;
	*reinterpret_cast<int64_t*>(stack[position]) = value;
	position++;
}

/*---- FLOAT ----*/

void Stack::Push (float value)
{
	if (!IsStackOpen()) return;
	*reinterpret_cast<double*>(stack[position]) = (double)value;
	position++;
}

void Stack::Push (double value)
{
	if (!IsStackOpen()) return;
	*reinterpret_cast<double*>(stack[position]) = value;
	position++;
}

/*----  Mathematics ----*/

void Stack::Add ()
{
	position--;
	uint64_t number_value_1 = *(uint64_t*)&stack[position][0];
	uint64_t number_value_2 = *(uint64_t*)&stack[position-1][0];
	
	
	uint64_t newValue = number_value_2 + number_value_1;
	*reinterpret_cast<uint64_t*>(stack[position-1]) = newValue;
	*reinterpret_cast<uint64_t*>(stack[position]) = 0;
}

void Stack::Sub ()
{
	position--;
	uint64_t number_value_1 = *(uint64_t*)&stack[position][0];
	uint64_t number_value_2 = *(uint64_t*)&stack[position-1][0];
	
	
	uint64_t newValue = number_value_2 - number_value_1;
	*reinterpret_cast<uint64_t*>(stack[position-1]) = newValue;
	*reinterpret_cast<uint64_t*>(stack[position]) = 0;
}

void Stack::Mul ()
{
	position--;
	uint64_t number_value_1 = *(uint64_t*)&stack[position][0];
	uint64_t number_value_2 = *(uint64_t*)&stack[position-1][0];
	
	
	uint64_t newValue = number_value_2 * number_value_1;
	*reinterpret_cast<uint64_t*>(stack[position-1]) = newValue;
	*reinterpret_cast<uint64_t*>(stack[position]) = 0;
}

void Stack::Div ()
{
	position--;
	uint64_t number_value_1 = *(uint64_t*)&stack[position][0];
	uint64_t number_value_2 = *(uint64_t*)&stack[position-1][0];
	
	
	uint64_t newValue = number_value_2 / number_value_1;
	*reinterpret_cast<uint64_t*>(stack[position-1]) = newValue;
	*reinterpret_cast<uint64_t*>(stack[position]) = 0;
}



void Stack::Add_i ()
{
	position--;
	int64_t number_value_1 = *(int64_t*)&stack[position][0];
	int64_t number_value_2 = *(int64_t*)&stack[position-1][0];
	
	
	int64_t newValue = number_value_2 + number_value_1;
	*reinterpret_cast<int64_t*>(stack[position-1]) = newValue;
	*reinterpret_cast<int64_t*>(stack[position]) = 0;
}

void Stack::Sub_i ()
{
	position--;
	int64_t number_value_1 = *(int64_t*)&stack[position][0];
	int64_t number_value_2 = *(int64_t*)&stack[position-1][0];
	
	
	int64_t newValue = number_value_2 - number_value_1;
	*reinterpret_cast<int64_t*>(stack[position-1]) = newValue;
	*reinterpret_cast<int64_t*>(stack[position]) = 0;
}

void Stack::Mul_i ()
{
	position--;
	int64_t number_value_1 = *(int64_t*)&stack[position][0];
	int64_t number_value_2 = *(int64_t*)&stack[position-1][0];
	
	
	int64_t newValue = number_value_2 * number_value_1;
	*reinterpret_cast<int64_t*>(stack[position-1]) = newValue;
	*reinterpret_cast<int64_t*>(stack[position]) = 0;
}

void Stack::Div_i ()
{
	position--;
	int64_t number_value_1 = *(int64_t*)&stack[position][0];
	int64_t number_value_2 = *(int64_t*)&stack[position-1][0];
	
	
	int64_t newValue = number_value_2 / number_value_1;
	*reinterpret_cast<int64_t*>(stack[position-1]) = newValue;
	*reinterpret_cast<int64_t*>(stack[position]) = 0;
}




void Stack::Add_f ()
{
	position--;
	double number_value_1 = *(double*)&stack[position][0];
	double number_value_2 = *(double*)&stack[position-1][0];
	
	
	double newValue = number_value_2 + number_value_1;
	*reinterpret_cast<double*>(stack[position-1]) = newValue;
	*reinterpret_cast<double*>(stack[position]) = 0;
}

void Stack::Sub_f ()
{
	position--;
	double number_value_1 = *(double*)&stack[position][0];
	double number_value_2 = *(double*)&stack[position-1][0];
	
	
	double newValue = number_value_2 - number_value_1;
	*reinterpret_cast<double*>(stack[position-1]) = newValue;
	*reinterpret_cast<double*>(stack[position]) = 0;
}

void Stack::Mul_f ()
{
	position--;
	double number_value_1 = *(double*)&stack[position][0];
	double number_value_2 = *(double*)&stack[position-1][0];
	
	
	double newValue = number_value_2 * number_value_1;
	*reinterpret_cast<double*>(stack[position-1]) = newValue;
	*reinterpret_cast<double*>(stack[position]) = 0;
}

void Stack::Div_f ()
{
	position--;
	double number_value_1 = *(double*)&stack[position][0];
	double number_value_2 = *(double*)&stack[position-1][0];
	
	
	double newValue = number_value_2 / number_value_1;
	*reinterpret_cast<double*>(stack[position-1]) = newValue;
	*reinterpret_cast<double*>(stack[position]) = 0;
}

void Stack::Pop (Register reg)
{
	ADDR address = engine->registerStack[reg.id];
	
	char* data = (char*)&stack[position];
	
	engine->memory->Write (address, data, MAX_BYTES);
}

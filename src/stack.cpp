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

void Stack::Pop (Register reg)
{
	printf("popping into %i\n", reg.id);
	
	ADDR address = engine->registerStack[reg.id];
	
	char* data = (char*)&stack[position];
	
	engine->memory->Write (address, data, MAX_BYTES);
}

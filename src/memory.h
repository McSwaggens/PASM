#pragma once

#include <algorithm>
#include <vector>
#include <stdint.h>
#include "globaldefines.h"

typedef uint16_t ADDR;

struct MemoryBlock;

class Memory
{
private:
// Member variables
	MemoryBlock*				memoryBlockStack;
	std::vector<MemoryBlock*>	freeBlocks;			// Array of memory blocks that aren't being used.
	std::vector<MemoryBlock*>	usedBlocks; 		// Array of memory blocks that are being used by one or more pointers
	
// Member functions
	MemoryBlock* GetFreeBlock	(unsigned short minimumSize); // Get a free block with the minimum required size
	void	Stitch	(MemoryBlock* memoryBlock);
	
public:
// Constructor
	Memory	(ADDR size);

// Member variables
	char*	data;
	ADDR	size;
	
// Member functions
	void	Write	(ADDR address, char* data, ADDR size);	// Write data to a given address
	char*	Read	(ADDR address, ADDR length);			// Read data from a given address and length
	ADDR	Malloc	(ADDR size);							// Allocate data with a given length
	void	Free	(ADDR address);
};

struct MemoryBlock			// 7 Bytes total
{
	ADDR	backAddress;	// 2 Bytes
	ADDR	address;		// 2 Bytes
	ADDR	size;			// 2 Bytes
	bool	used;			// 1 Byte
	
	MemoryBlock ()
	{
	}
	
	MemoryBlock (ADDR address, unsigned int size)
	{
		this->address = address;
		this->size = size;
		
		this->backAddress = 0;	// Default value
	}
	
	
	inline ADDR GetNextAddress ()
	{
		return this->address + this->size;
	}
};

#pragma once

#include <vector>
#include <stdlib.h>
#include "globaldefines.h"

typedef unsigned long ulong; // Made this so I can keep Malloc definition clean

struct MemoryBlock;

class Memory
{
private:
// Member variables
	void* memoryBlockAddressStack;
	std::vector<MemoryBlock> freeParts;
	std::vector<MemoryBlock> usedParts;
	
// Member functions
	MemoryBlock* GetFreeBlock (unsigned short minimumSize); // Get a free block with the minimum required size
	
	
public:
// Constructor
	Memory (unsigned long size);

// Member variables
	char*			data;
	unsigned long	size;
	
// Member functions
	void	Write	(unsigned long address, char* data);			// Write data to a given address
	char*	Read	(unsigned long address, unsigned long length);	// Read data from a given address and length
	ulong	Malloc	(unsigned long length);							// Allocate data with a given length
};

struct MemoryBlock // 15 Bytes
{
	unsigned int	backAddress;	// 4 Bytes
	unsigned long	address;		// 8 Bytes
	unsigned short	size;			// 2 Bytes
	bool			used;			// 1 Byte
	
	MemoryBlock (unsigned long address, unsigned int size)
	{
		this->address = address;
		this->size = size;
	}
	
	unsigned long GetNextAddress ()
	{
		return address + size;
	}
};
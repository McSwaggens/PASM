#pragma once

typedef unsigned long ulong; // Made this so I can keep Malloc definition clean


class Memory
{
private:
	
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
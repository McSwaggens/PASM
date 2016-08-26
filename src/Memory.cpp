#include "Memory.h"

// Memory Constructor
Memory::Memory (unsigned long size)
{
	// Create a byte array with the given size
	data = new char[size];
	
	// Set the public size
	this->size = size;
}

// Write data to an address
void Memory::Write (unsigned long address, char* data)
{
	// Get the size of the data we're writing with
	unsigned int dataSize = sizeof(data);
	
	// Loop through the size of the data we're writing with
	for (unsigned int offset = 0; offset < dataSize; dataSize++)
	{
		// Set the data of the address + offset to the offset in the data we're wring with
		this->data[address + offset] = data[offset];
	}
}

// Write some memory to a given address
char* Memory::Read (unsigned long address, unsigned long length)
{
	// Create a buffer with the correct length to be returned
	char* data = new char[length];
	
	// Loop through the length of the data
	for (unsigned int offset = 0; offset < length; offset++)
	{
		// Add the byte of data into the buffer
		data[offset] = this->data[address + offset];
	}
	
	// Return the address of the data
	return data;
}

/*	Malloc -> Memory Allocate
	
	Malloc allocates an unused section of bytes in memory, making sure it isn't used
*/
void Memory::Malloc (unsigned long length)
{
}
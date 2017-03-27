#include "memory.h"

#define DATA(v) reinterpret_cast<char*>(&v)
#define CAST(t, v) *reinterpret_cast<t*>(v)

// Memory Constructor
Memory::Memory (ADDR size)
{
	// Create a byte array with the given size
	data = new char[size];
	memoryBlockStack = new MemoryBlock[size];
	
	MemoryBlock memoryBlock (0, size);
	
	memoryBlockStack[0] = memoryBlock;
	freeBlocks.push_back (&memoryBlockStack[0]);
	
	// Set the public size
	this->size = size;
}

// Get a free block with the minimum required size
MemoryBlock* Memory::GetFreeBlock (uint16_t minimumSize)
{
	for (int i = 0; i < freeBlocks.size(); i++)
	{
		MemoryBlock* block = freeBlocks[i];
		if (block->size >= minimumSize)
		{	// A memory block has been found with at or above the required size
			return block;
		}
	}
	
	// Couldn't find a free memory block with the required size
	// ERROR!
	
	throw MEMORY_EXCEPTION;
}

void Memory::Stitch (MemoryBlock* base_block)
{
	// Check if the block above the current is used,	-
	//	and if so, we want to expand the currents size,	-
	//	removing the block above.
	
	if (base_block->GetNextAddress() < size)
	{
		MemoryBlock* next_block = &memoryBlockStack[base_block->GetNextAddress()];
		
		if (!next_block->used)
		{
			// Expand the base_blocks size
			base_block->size += next_block->size;
			
			// Remove the block from the list of free blocks
			freeBlocks.erase (std::remove(freeBlocks.begin(), freeBlocks.end(), next_block));
			
			// Set the next memoryBlock's backAddress to the current address
			
			// Check if it is possible to have a next block (any more blocks) (No more memory blocks above the current)
			if (next_block->GetNextAddress() < size)
			{
				memoryBlockStack[next_block->GetNextAddress()].backAddress = base_block->address;
			}
		}
	}
	
	
	// Check if the address is not 0 (No blocks under itself)
	if (base_block->address != 0)
	{
		
		
		// Get the previous block
		MemoryBlock* prev_block = &memoryBlockStack[base_block->backAddress];
		
		// Check if the previous memory block is in use
		if (!prev_block->used)
		{
			// Expand the size
			prev_block->size += base_block->size;
			
			// Remove it from the vector of free memory blocks
			freeBlocks.erase (std::remove(freeBlocks.begin(), freeBlocks.end(), base_block));
			
			// Check if it is possible to have a next_block
			if (base_block->GetNextAddress() < size)
			{
				MemoryBlock* next_block = &memoryBlockStack[base_block->GetNextAddress()];
				// Update the back address
				next_block->backAddress = prev_block->address;
			}
		}
	}
}



// Write data to an address
void Memory::Write (ADDR address, char* data, ADDR size)
{
	// Loop through the size of the data we're writing with
	for (ADDR offset = 0; offset < size; offset++)
	{
		// Set the data of the address + offset to the offset in the data we're wring with
		this->data[address + offset] = data[offset];
	}
}

// Write some memory to a given address
char* Memory::Read (ADDR address, ADDR length)
{
	// Create a buffer with the correct length to be returned
	char* data = new char[length];
	
	// Loop through the length of the data
	for (uint32_t offset = 0; offset < length; offset++)
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
ADDR Memory::Malloc (ADDR size)
{
	MemoryBlock* memoryBlock = GetFreeBlock (size);
	
	if (memoryBlock->size > size)
	{
		MemoryBlock* newBlock = &memoryBlockStack[memoryBlock->address + size];
		newBlock->address = memoryBlock->address + size;
		newBlock->size = memoryBlock->size - size;
		newBlock->backAddress = memoryBlock->address;
		newBlock->used = false;
		
		freeBlocks.insert (freeBlocks.begin(), newBlock);
		
		if (newBlock->GetNextAddress() < this->size)
		{
			MemoryBlock* newBlock_next = &memoryBlockStack[newBlock->GetNextAddress()];
			newBlock_next->backAddress = newBlock->address;
		}
		
		memoryBlock->size = size;
		
	}
	
	memoryBlock->used = true;
	freeBlocks.erase (std::remove(freeBlocks.begin(), freeBlocks.end(), memoryBlock));
	usedBlocks.push_back (memoryBlock);
	
	return memoryBlock->address;
}



void Memory::Free (ADDR address)
{
	MemoryBlock* memoryBlock = &memoryBlockStack[address];
	memoryBlock->used = false;
	usedBlocks.erase (std::remove(usedBlocks.begin(), usedBlocks.end(), memoryBlock));
	freeBlocks.insert (freeBlocks.begin(), memoryBlock);
	Stitch (memoryBlock);
}

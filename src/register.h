#pragma once

#include <stdint.h>

struct Register
{
	bool is_private = false;
	uint16_t id;
}; // Size = 3 bytes

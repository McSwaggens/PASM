#ifndef __REGISTER_H_
#define __REGISTER_H_

struct Register
{
public:
	bool isPrivate = false;
	unsigned short id;
}; // Size = 3 bytes

#endif
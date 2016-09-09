#ifndef __INT32_H_
#define __INT32_H_

#include "../set.h"

class SET_INT32 : public SET
{
private:
	unsigned int number;
public:
	SET_INT32 (unsigned int targetRegister, unsigned int number);
	virtual void Execute();
};

#endif
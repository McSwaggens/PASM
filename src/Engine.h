#include <iostream>
#include <stdio.h>
#include <string>
#include "string.h"
#include <vector>
#include "Memory.h"
#include "Handler.h"
#include "Parser.h"
#include "GlobalDefines.h"

using namespace std;

class Engine
{
private:
	Handler* code;
public:
	Engine();
	void Load (string code);
	void Execute (int lines);
	void Initialize ();
};
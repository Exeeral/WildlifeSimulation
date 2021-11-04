#include <iostream>

#include "Handler.h"

int main()
{
	Handler* handler{ new Handler{3, 3, 10} };

	handler->populateWorld(5, 3);

	handler->startSimulation();

	return 0;
}
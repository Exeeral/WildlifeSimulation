#include <iostream>

#include "Handler.h"

int main()
{
	Handler* handler{ new Handler{10, 10, 50} };

	handler->populateWorld(2, 10);

	handler->startSimulation();

	return 0;
}
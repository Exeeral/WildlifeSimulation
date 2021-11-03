#include <iostream>

#include "Handler.h"

int main()
{
	Handler* handler{ new Handler{5, 5, 50} };

	handler->populateWorld(5, 5);

	handler->startSimulation();

	return 0;
}
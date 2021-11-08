#include <iostream>

#include "Simulation.h"

int main()
{
	Simulation* simulation{ new Simulation{4, 4, 20} };

	simulation->populateWorld(10, 3);

	simulation->startSimulation();

	return 0;
}
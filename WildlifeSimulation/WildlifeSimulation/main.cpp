#include "Simulation.h"

int main()
{
	Simulation* simulation{ new Simulation{3, 3, 20} };

	simulation->populateWorld(5, 3);

	simulation->startSimulation();

	return 0;
}
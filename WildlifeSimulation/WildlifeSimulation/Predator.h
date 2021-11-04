#ifndef PREDATOR_H
#define PREDATOR_H

#include "Animal.h"

class Predator : public Animal
{
private:

	int m_turnsTillStarvation{};
	bool m_hasEaten{};
	inline static int totalAmountOfPredators{};

public:

	inline static constexpr int maxHungerTillDeath{ 2 };

	Predator(bool sex);
	~Predator() override;

	void setHasEaten(bool input);
	void increaseHunger();
	void resetHunger();

	bool isPredator() const override;
	bool hasEaten() const;
	int getTurnsTillStarvation() const;

	inline static int getTotalAmountOfPredators()
	{
		return totalAmountOfPredators;
	}
};

#endif
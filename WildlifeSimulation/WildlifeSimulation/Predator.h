#ifndef PREDATOR_H
#define PREDATOR_H

#include "Animal.h"

class Predator : public Animal
{
private:

	int m_turnsTillStarvation{};
	bool m_hasEaten{};

public:

	static constexpr int maxHungerTillDeath{ 2 };

	Predator(const bool isMale) noexcept;
	~Predator() noexcept override;

	void setHasEaten(const bool input);
	void increaseHunger();
	void resetHunger();

	const bool isPredator() const override;
	const bool hasEaten() const;
	const int getTurnsTillStarvation() const;

	inline static const int getTotalAmountOfPredators()
	{
		return totalAmountOfPredators;
	}
};

#endif
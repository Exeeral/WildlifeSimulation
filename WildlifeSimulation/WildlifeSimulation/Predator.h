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

	bool isPredator() const override;
	bool hasEaten() const;
	int getTurnsTillStarvation() const;
};

#endif
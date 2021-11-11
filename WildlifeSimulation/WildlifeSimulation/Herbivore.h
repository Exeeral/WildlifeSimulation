#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "Animal.h"

class Herbivore : public Animal
{
public:

	Herbivore(const bool isMale) noexcept;
	~Herbivore() noexcept override;

	bool isPredator() const override;
};

#endif
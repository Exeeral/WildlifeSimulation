#include "Tile.h"
#include "UtilityFunctions.h"
#include "Predator.h"
#include "Herbivore.h"

Tile::Tile(int x, int y) noexcept
	:m_xCoordinate{ x },
	m_yCoordinate{ y }
{

}

void Tile::addAnimalToTile(Animal* animal)
{
	if (!animal)
	{
		UtilityFunctions::printNullptrError();

		return;
	}

	m_animalsOnTile.push_back(animal);
	animal->setCurrentTile(this);

	if (animal->isPredator())
	{
		animal->isMale() ? ++m_malePredators : ++m_femalePredators;

	}
	else
	{
		animal->isMale() ? ++m_maleHerbivores : ++m_femaleHerbivores;

	}

	std::cout << "New " << *animal << " arrived on " << *this << '\n';
}

bool Tile::areAnimalsOnTile() const
{
	return m_animalsOnTile.size();
}

void Tile::removeAnimal(Animal* animal)
{
	if (!animal)
	{
		UtilityFunctions::printNullptrError();
		return;
	}

	auto animalFound{ std::find_if(m_animalsOnTile.begin(), m_animalsOnTile.end(), [&animal](const Animal* currentAnimal)
	{
		return animal->getId() == currentAnimal->getId();
	})
	};

	if (animalFound != m_animalsOnTile.end())
	{
		if (animal->isPredator())
		{
			animal->isMale() ? --m_malePredators : --m_femalePredators;
		}
		else
		{
			animal->isMale() ? --m_maleHerbivores : --m_femaleHerbivores;
		}

		static_cast<Animal*>(*animalFound)->setCurrentTile(nullptr);
		m_animalsOnTile.erase(animalFound);
	}
	else
	{
		std::cout << "Tile::removeAnimal ERROR: animal not found!\n";
	}
}

void Tile::resetAnimalsState()
{
	for (auto& currentAnimal : m_animalsOnTile)
	{
		currentAnimal->setHasMoved(false);

		if (currentAnimal->isPredator())
		{
			dynamic_cast<Predator*>(currentAnimal)->setHasEaten(false);
		}
	}
}

void Tile::findPredatorAndEatHerbivore()
{
	for (int i{ 0 }; i < getAmountOfPredatorsOnTile(); ++i)
	{
		auto predatorFound{ std::find_if(m_animalsOnTile.begin() + i, m_animalsOnTile.end(), [](Animal* currentAnimal)
			{
				return currentAnimal->isPredator();
			}) 
		};

		if (predatorFound != m_animalsOnTile.end())
		{
			Predator* predator{ dynamic_cast<Predator*>(*predatorFound) };

			if (getAmountOfHerbivoresOnTile() > 0)
			{
				if (!predator->hasEaten())
				{
					auto herbivoreFound{ std::find_if(m_animalsOnTile.begin(), m_animalsOnTile.end(), [](Animal* currentAnimal)
						{
							return !currentAnimal->isPredator();
						})
					};

					Herbivore* herbivore{ dynamic_cast<Herbivore*>(*herbivoreFound) };

					if (herbivoreFound != m_animalsOnTile.end())
					{
						std::cout << *predator << " eats " << *herbivore << " on " << *this << ".\n";

						removeAnimal(herbivore);
						delete herbivore;

						predator->setHasEaten(true);
						predator->resetHunger();

						continue;
					}
				}
			}

			predator->increaseHunger();

			if (predator->getTurnsTillStarvation() == 0)
			{
				std::cout << *predator << " starved to death at " << *this << '\n';

				removeAnimal(predator);
				delete predator;

			}
		}
	}
}

void Tile::printAnimalsInfo() const
{
	for (auto& currentAnimal : m_animalsOnTile)
	{
		std::cout << *currentAnimal << " on " << *this << '\n';
	}
}

int Tile::getAmountOfAnimalsOnTile() const
{
	return static_cast<int>(m_animalsOnTile.size());
}

int Tile::getAmountOfPredatorsOnTile() const
{
	return m_femalePredators + m_malePredators;
}

int Tile::getAmountOfHerbivoresOnTile() const
{
	return m_femaleHerbivores + m_maleHerbivores;
}

int Tile::getXCoordinate() const
{
	return m_xCoordinate;
}

int Tile::getYCoordinate() const
{
	return m_yCoordinate;
}

Animal* Tile::getAnimalOnIndex(const int index) const
{
	return m_animalsOnTile[index];
}

int Tile::getAmountOfHerbivoreBreeds() const
{
	if (m_maleHerbivores > 0 && m_femaleHerbivores > 0)
	{
		if (m_maleHerbivores > m_femaleHerbivores)
		{
			return m_maleHerbivores - (m_maleHerbivores - m_femaleHerbivores);
		}
		else
		{
			return m_femaleHerbivores - (m_femaleHerbivores - m_maleHerbivores);
		}
	}

	return 0;
}

int Tile::getAmountOfPredatorBreeds() const
{
	if (m_malePredators > 0 && m_femalePredators > 0)
	{
		if (m_malePredators > m_femalePredators)
		{
			return m_malePredators - (m_malePredators - m_femalePredators);
		}
		else
		{
			return m_femalePredators - (m_femalePredators - m_malePredators);
		}
	}

	return 0;
}

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
	out << "Tile(X: " << tile.m_xCoordinate 
		<< ", Y: " << tile.m_yCoordinate << ")";

	return out;
}
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void)
	:	Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	return;
}

SuperMutant::SuperMutant(SuperMutant const& src)
{
	*this = src;
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	return;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
	return;
}

SuperMutant& SuperMutant::operator=(SuperMutant const& rhs)
{
	this->hp_ = rhs.hp_;
	this->type_ = rhs.type_;
	return *this;
}

void SuperMutant::takeDamage(int amount)
{
	this->Enemy::takeDamage(amount - 3);
}

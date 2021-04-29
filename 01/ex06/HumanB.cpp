#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	:	name_(name),
		weapon_(NULL)
{
	return;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon_ = &weapon;
}

void	HumanB::attack(void) const
{
	std::cout << this->name_ << " attacks with his "
		<< this->weapon_->getType() << std::endl;
}

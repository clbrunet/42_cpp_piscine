#include "Weapon.hpp"

Weapon::Weapon(void)
	:	type_("")
{
	return;
}
Weapon::Weapon(std::string type)
	:	type_(type)
{
	return;
}

std::string const	&Weapon::getType(void) const
{
	return (this->type_);
}

void	Weapon::setType(std::string type)
{
	this->type_ = type;
	return;
}

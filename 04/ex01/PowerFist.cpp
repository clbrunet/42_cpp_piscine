#include "PowerFist.hpp"

PowerFist::PowerFist(void)
	:	AWeapon("Power Fist", 8, 50)
{
	return;
}

PowerFist::PowerFist(PowerFist const& src)
{
	*this = src;
	return;
}

PowerFist::~PowerFist()
{
	return;
}

PowerFist& PowerFist::operator=(PowerFist const& rhs)
{
	this->name_ = rhs.name_;
	this->damage_ = rhs.damage_;
	this->ap_cost_ = rhs.ap_cost_;
	return *this;
}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void)
	:	AWeapon("Plasma Rifle", 5, 21)
{
	return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const& src)
{
	*this = src;
	return;
}

PlasmaRifle::~PlasmaRifle()
{
	return;
}

PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const& rhs)
{
	this->name_ = rhs.name_;
	this->damage_ = rhs.damage_;
	this->ap_cost_ = rhs.ap_cost_;
	return *this;
}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

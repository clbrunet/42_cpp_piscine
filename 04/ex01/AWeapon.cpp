#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
	:	name_(name),
		ap_cost_(apcost),
		damage_(damage)
{
	return;
}

AWeapon::~AWeapon()
{
	return;
}

std::string const& AWeapon::getName() const
{
	return this->name_;
}

int AWeapon::getAPCost() const
{
	return this->ap_cost_;
}

int AWeapon::getDamage() const
{
	return this->damage_;
}

AWeapon::AWeapon(void)
	:	name_(""),
		ap_cost_(0),
		damage_(0)
{
	return;
}

AWeapon::AWeapon(AWeapon const& src)
{
	*this = src;
	return;
}

AWeapon& AWeapon::operator=(AWeapon const& rhs)
{
	this->name_ = rhs.name_;
	this->damage_ = rhs.damage_;
	this->ap_cost_ = rhs.ap_cost_;
	return *this;
}

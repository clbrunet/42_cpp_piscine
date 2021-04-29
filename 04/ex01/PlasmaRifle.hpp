#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include <iostream>

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const& src);
	virtual ~PlasmaRifle();
	PlasmaRifle& operator=(PlasmaRifle const& rhs);

	virtual void attack() const;

};

#endif

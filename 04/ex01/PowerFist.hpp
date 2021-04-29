#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include <iostream>

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist(void);
	PowerFist(PowerFist const& src);
	virtual ~PowerFist();
	PowerFist& operator=(PowerFist const& rhs);

	virtual void attack() const;

};

#endif

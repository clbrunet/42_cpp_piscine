#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>

class AWeapon
{
protected:
	std::string name_;
	int ap_cost_;
	int damage_;

	AWeapon(void);
	AWeapon(AWeapon const& src);
	AWeapon& operator=(AWeapon const& rhs);

public:
	AWeapon(std::string const & name, int apcost, int damage);
	virtual ~AWeapon();
	std::string const& getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
};

#endif

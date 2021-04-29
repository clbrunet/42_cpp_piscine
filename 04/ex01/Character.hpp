#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
private:
	std::string name_;
	int ap_;
	AWeapon* weapon_;

	Character(void);

public:
	Character(std::string const & name);
	Character(Character const& src);
	Character& operator=(Character const& rhs);
	~Character();
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	std::string const& getName() const;
	int getAP() const;
	AWeapon const* getWeapon() const;
};

std::ostream& operator<<(std::ostream& ostream, Character const& rhs);

#endif

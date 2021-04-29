#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character(std::string name);
	Character(Character const& src);
	Character& operator=(Character const& rhs);
	virtual ~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	Character();

	std::string _name;
	unsigned int _nb_materias;
	AMateria* _inventory[4];
};

#endif

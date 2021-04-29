#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	// [...]
	AMateria();

	std::string _type;
	unsigned int _xp;

public:
	AMateria(std::string const & type);
	AMateria(AMateria const& src);
	AMateria& operator=(AMateria const& rhs);
	// [...]
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	unsigned int getXP() const; //Returns the Materia's XP
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif

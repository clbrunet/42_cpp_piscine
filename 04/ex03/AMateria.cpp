#include "AMateria.hpp"

AMateria::AMateria()
	:	_type(""),
		_xp(0)
{
	return;
}

AMateria::AMateria(std::string const & type)
	:	_type(type),
		_xp(0)
{

}

AMateria::AMateria(AMateria const& src)
{
	*this = src;
	return;
}

AMateria& AMateria::operator=(AMateria const& rhs)
{
	this->_xp = rhs._xp;
	return *this;
}

AMateria::~AMateria()
{
	return;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

unsigned int AMateria::getXP() const
{
	return this->_xp;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	this->_xp += 10;
}

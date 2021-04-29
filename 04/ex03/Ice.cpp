#include "Ice.hpp"

Ice::Ice()
	:	AMateria("ice")
{
	return;
}

Ice::Ice(Ice const& src)
	:	AMateria(src)
{
	return;
}

Ice& Ice::operator=(Ice const& rhs)
{
	this->AMateria::operator=(rhs);
	return *this;
}

Ice::~Ice()
{
	return;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
		<< std::endl;
	this->AMateria::use(target);
}

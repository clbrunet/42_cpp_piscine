#include "Cure.hpp"

Cure::Cure()
	:	AMateria("cure")
{
	return;
}

Cure::Cure(Cure const& src)
	:	AMateria(src)
{
	return;
}

Cure& Cure::operator=(Cure const& rhs)
{
	this->AMateria::operator=(rhs);
	return *this;
}

Cure::~Cure()
{
	return;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *"
		<< std::endl;
	this->AMateria::use(target);
}

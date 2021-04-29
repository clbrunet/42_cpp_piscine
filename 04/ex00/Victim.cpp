#include "Victim.hpp"

Victim::Victim(std::string name)
	:	name_(name)
{
	std::cout << "Some random victim called " << this->name_
		<< " just appeared!" << std::endl;
	return;
}

Victim::Victim(Victim const& src)
{
	*this = src;
	std::cout << "Some random victim called " << this->name_
		<< " just appeared!" << std::endl;
	return;
}
Victim::~Victim(void)
{
	std::cout << "Victim " << this->name_ <<
		" just died for no apparent reason!" << std::endl;
	return;
}

Victim& Victim::operator=(Victim const& rhs)
{
	this->name_ = rhs.name_;
	return *this;
}

std::string Victim::name(void) const
{
	return this->name_;
}

void Victim::getPolymorphed(void) const
{
	std::cout << this->name_
		<< " has been turned into a cute little sheep!" << std::endl;
}

Victim::Victim(void)
{
	return;
}

std::ostream& operator<<(std::ostream& ostream, Victim const& rhs)
{
	std::cout << "I'm " << rhs.name() << " and I like otters!"
		<< std::endl;
	return ostream;
}

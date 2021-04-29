#include "Peon.hpp"

Peon::Peon(std::string name)
	:	Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::Peon(Victim const& src)
{
	*this = src;
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
	return;
}

Peon& Peon::operator=(Peon const& src)
{
	this->name_ = src.name_;
	return *this;
}

void Peon::getPolymorphed(void) const
{
	std::cout << this->name_
		<< " has been turned into a pink pony!" << std::endl;
}

Peon::Peon(void)
	:	Victim()
{
	return;
}

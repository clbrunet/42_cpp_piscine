#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
	:	name_(name),
		title_(title)
{
	std::cout << this->name_ << ", " << this->title_ << ", is born!"
		<< std::endl;
	return;
}

Sorcerer::Sorcerer(Sorcerer const& src)
{
	*this = src;
	std::cout << this->name_ << ", " << this->title_ << ", is born!"
		<< std::endl;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->name_ << ", " << this->title_
		<< ", is dead. Consequences will never be the same!"
		<< std::endl;
	return;
}
Sorcerer& Sorcerer::operator=(Sorcerer const& rhs)
{
	this->name_ = rhs.name_;
	this->title_ = rhs.title_;
	return *this;
}

std::string Sorcerer::name(void) const
{
	return this->name_;
}

std::string Sorcerer::title(void) const
{
	return this->title_;
}

void Sorcerer::polymorph(Victim const& victim) const
{
	victim.getPolymorphed();
}


Sorcerer::Sorcerer(void)
	:	name_(""),
		title_("")
{
	return;
}

std::ostream& operator<<(std::ostream& ostream, Sorcerer const& rhs)
{
	ostream << "I am " << rhs.name() << ", " << rhs.title()
		<< ", and I like ponies!" << std::endl;
	return ostream;
}

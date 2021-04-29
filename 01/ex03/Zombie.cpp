#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(void)
	:	type_(""),
		name_("")
{
	std::cout << "Create a anonymous Zombie." << std::endl;
	return;
}

Zombie::Zombie(std::string type, std::string name)
	:	type_(type),
		name_(name)
{
	std::cout << "Create a Zombie named '" << this->name_
		<< "' with type '" << this->type_ << "'." << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie named '" << this->name_
		<< "' with type '" << this->type_ << "' died." << std::endl;
}

void	Zombie::fill(std::string type, std::string name)
{
	this->type_ = type;
	this->name_ = name;
	std::cout << "Filling zombie named '" << this->name_
		<< "' with type '" << this->type_ << "'." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->name_ << " (" << this->type_
		<< ")> Braiiiiiiinnnssss ..." << std::endl;
}

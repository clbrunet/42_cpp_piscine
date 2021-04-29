#include <iostream>

#include "Pony.hpp"

Pony::Pony(std::string name, std::string color)
	:	name_(name),
		color_(color)
{
	std::cout << "Creation of a " << this->color_ << " pony named " << this->name_ << "." << std::endl;
	return;
}

Pony::~Pony(void)
{
	std::cout << "Pony " << this->name_ << " died." << std::endl;
	return;
}

void	Pony::describe(void)
{
	std::cout << "I am " << this->name_ << " and my color is " << this->color_ << "." << std::endl;
}


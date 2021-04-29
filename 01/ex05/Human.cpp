#include "Human.hpp"

std::string	Human::identify(void) const
{
	return (this->brain_.identify());
}

Brain const	&Human::getBrain(void) const
{
	return (this->brain_);
}

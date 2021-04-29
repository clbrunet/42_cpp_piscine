#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>

#include "Brain.hpp"

class Human {
public:
	std::string	identify(void) const;
	Brain const	&getBrain(void) const;
private:
	Brain const	brain_;
};

#endif

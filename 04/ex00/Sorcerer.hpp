#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <string>
#include <iostream>

#include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const& src);
	~Sorcerer(void);
	Sorcerer& operator=(Sorcerer const& rhs);

	std::string name(void) const;
	std::string title(void) const;

	void polymorph(Victim const& victim) const;

private:
	Sorcerer(void);

	std::string name_;
	std::string title_;
};

std::ostream& operator<<(std::ostream& ostream, Sorcerer const& rhs);

#endif

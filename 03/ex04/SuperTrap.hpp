#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
	SuperTrap(void);
	SuperTrap(std::string const& name);
	SuperTrap(SuperTrap const& src);
	~SuperTrap(void);

	SuperTrap& operator=(SuperTrap const& rhs);
};

#endif

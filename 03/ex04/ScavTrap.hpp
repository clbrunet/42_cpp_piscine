#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string const& name);
	ScavTrap(ScavTrap const& src);
	~ScavTrap(void);

	ScavTrap& operator=(ScavTrap const& rhs);

	void challengeNewcomer(std::string const & target) const;
};

#endif

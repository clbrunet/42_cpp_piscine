#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string const& name);
	FragTrap(FragTrap const& src);
	~FragTrap(void);

	FragTrap& operator=(FragTrap const& rhs);

	void vaulthunter_dot_exe(std::string const & target);
};

#endif

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap(std::string const& name);
	NinjaTrap(NinjaTrap const& src);
	~NinjaTrap(void);

	NinjaTrap& operator=(NinjaTrap const& rhs);

	void ninjaShoebox(NinjaTrap const& target) const;
	void ninjaShoebox(FragTrap const& target) const;
	void ninjaShoebox(ScavTrap const& target) const;
};

#endif

#include <iostream>

#include "ZombieHorde.hpp"

int	main(void)
{
	ZombieHorde	zombie_horde(10);
	std::cout << std::endl;
	zombie_horde.announce();
	std::cout << std::endl;
	return (0);
}

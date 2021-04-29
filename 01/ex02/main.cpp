#include <iostream>

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

static void	test_Zombie(void)
{
	Zombie	zombie("Brain Star Chef", "Gusteau");
	zombie.announce();
	return;
}

static void	test_ZombieEvent_newZombie(void)
{
	ZombieEvent	zombie_event;

	zombie_event.setZombieType("Born from a dynamic allocation");
	Zombie	*zombie = zombie_event.newZombie("Ralph");
	zombie->announce();
	delete zombie;
	return;
}

static void	test_ZombieEvent_randomChump(void)
{
	ZombieEvent	zombie_event;

	zombie_event.setZombieType("RNG");
	zombie_event.randomChump();
	return;
}

int	main(void)
{
	test_Zombie();
	std::cout << std::endl;
	test_ZombieEvent_newZombie();
	std::cout << std::endl;
	test_ZombieEvent_randomChump();
	return (0);
}

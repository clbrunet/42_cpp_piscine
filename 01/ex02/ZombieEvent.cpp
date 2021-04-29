#include <cstdlib>
#include <ctime>
#include <iostream>

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
	:	zombie_type_("")
{
	std::cout << "Creation of a ZombieEvent." << std::endl;
	return;
}

ZombieEvent::ZombieEvent(std::string zombie_type)
	:	zombie_type_(zombie_type)
{
	std::cout << "Creation of a ZombieEvent with type '"
		<< this->zombie_type_ << "'." << std::endl;
	return;
}

ZombieEvent::~ZombieEvent(void)
{
	std::cout << "Destruction of a ZombieEvent with type '"
		<< this->zombie_type_ << "'." << std::endl;
	return;
}

void	ZombieEvent::setZombieType(std::string zombie_type)
{
	this->zombie_type_ = zombie_type;
	std::cout << "Zombie type set to '"
		<< this->zombie_type_ << "'." << std::endl;
	return;
}

Zombie*	ZombieEvent::newZombie(std::string name) const
{
	Zombie	*zombie = new Zombie(this->zombie_type_, name);
	return (zombie);
}

void	ZombieEvent::randomChump(void) const
{
	std::string	name = "";
	srand(time(NULL));
	switch (rand() % 5) {
		case 0:
			name = "//\\(oo)/\\\\";
			break;
		case 1:
			name = "The One";
			break;
		case 2:
			name = "Jacob";
			break;
		case 3:
			name = "Really a chump";
			break;
		case 4:
			name = "Titouan";
			break;
		default:
			name = "VERY RANDOM WTF";
	}
	Zombie	chump(this->zombie_type_, name);
	chump.announce();
	return;
}

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <string>

#include "Zombie.hpp"

class ZombieEvent {
public:
	ZombieEvent(void);
	ZombieEvent(std::string type);
    ~ZombieEvent(void);

	void	setZombieType(std::string zombie_type);
	Zombie*	newZombie(std::string name) const;
	void	randomChump(void) const;

private:
	std::string	zombie_type_;
};

#endif

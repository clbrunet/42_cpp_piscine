#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <string>

#include "Zombie.hpp"

class ZombieHorde {
public:
	ZombieHorde(int n);
    ~ZombieHorde(void);

	void	announce(void);

private:
	std::string	zombies_type_;
	int			nb_zombies_;
	Zombie		*zombies_;
};

#endif

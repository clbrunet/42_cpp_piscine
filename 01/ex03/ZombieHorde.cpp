#include <cstdlib>
#include <ctime>
#include <iostream>

#include "ZombieHorde.hpp"

static std::string	get_random_name(void)
{
	std::string	name = "";
	switch (rand() % 10) {
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
		case 5:
			name = "Dobby";
			break;
		case 6:
			name = "Lavoisier";
			break;
		case 7:
			name = "Xavier Niel";
			break;
		case 8:
			name = "¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸";
			break;
		case 9:
			name = "girafon bleu";
			break;
		default:
			name = "VERY RANDOM WTF";
	}
	return (name);
}

ZombieHorde::ZombieHorde(int n)
	:	zombies_type_("normal"),
		nb_zombies_(n)
{
	if (this->nb_zombies_ < 1) {
		std::cout << n
			<< " zombies are not enough for the proper creation of a ZombieHorde."
			<< std::endl;
		return;
	}
	std::cout << "Creation of a ZombieHorde with " << n
		<< " normal zombies." << std::endl << std::endl;
	this->zombies_ = new Zombie[this->nb_zombies_];
	std::cout << std::endl;
	srand(time(NULL));
	for (int i = 0; i < nb_zombies_; i++) {
		this->zombies_[i].fill(this->zombies_type_, get_random_name());
	}
	return;
}

ZombieHorde::~ZombieHorde(void)
{
	if (this->nb_zombies_ >= 1) {
		delete [] this->zombies_;
	}
	std::cout << std::endl;
	std::cout << "Destruction of a ZombieHorde." << std::endl;
	return;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->nb_zombies_; i++) {
		this->zombies_[i].announce();
	}
	return;
}

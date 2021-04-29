#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	:	hit_points_(100),
		max_hit_points_(100),
		energy_points_(100),
		max_energy_points_(100),
		level_(1),
		name_("Robby"),
		melee_attack_damage_(30),
		ranged_attack_damage_(20),
		armor_damage_reduction_(5)
{
	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	FragTrap::srand();
	return;
}

FragTrap::FragTrap(std::string const& name)
	:	hit_points_(100),
		max_hit_points_(100),
		energy_points_(100),
		max_energy_points_(100),
		level_(1),
		name_(name),
		melee_attack_damage_(30),
		ranged_attack_damage_(20),
		armor_damage_reduction_(5)
{
	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	FragTrap::srand();
	return;
}

FragTrap::FragTrap(FragTrap const& src)
{
	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	*this = src;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "I'm too pretty to die!" << std::endl;
	return;
}

FragTrap& FragTrap::operator=(FragTrap const& rhs)
{
	this->hit_points_ = rhs.hit_points_;
	this->max_hit_points_ = rhs.max_hit_points_;
	this->energy_points_ = rhs.energy_points_;
	this->max_energy_points_ = rhs.max_energy_points_;
	this->level_ = rhs.level_;
	this->name_ = rhs.name_;
	this->melee_attack_damage_ = rhs.melee_attack_damage_;
	this->ranged_attack_damage_ = rhs.ranged_attack_damage_;
	this->armor_damage_reduction_ = rhs.armor_damage_reduction_;
	return *this;
}

void FragTrap::rangedAttack(std::string const & target) const
{
	std::cout << "FR4G-TP " << this->name_ << " attacks " << target
		<< " at range, causing " << this->ranged_attack_damage_
		<< " points of damage!" << std::endl;
	return;
}

void FragTrap::meleeAttack(std::string const & target) const
{
	std::cout << "FR4G-TP " << this->name_ << " attacks " << target
		<< " at close-range, causing " << this->melee_attack_damage_
		<< " points of damage!" << std::endl;
	return;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (amount < this->armor_damage_reduction_) {
		amount = 0;
	}
	else if (amount - this->armor_damage_reduction_ > this->hit_points_) {
		amount = this->hit_points_;
	}
	std::cout << "FR4G-TP " << this->name_ << " takes " << amount
		<< " points of damage!" << std::endl; 
	this->hit_points_ -= amount;
	return;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points_ + amount > this->max_hit_points_) {
		amount = this->max_hit_points_ - this->hit_points_;
	}
	std::cout << "FR4G-TP " << this->name_ << " gains " << amount
		<< " hit points!" << std::endl; 
	this->hit_points_ += amount;
	return;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->energy_points_ < 25) {
		std::cout << "FR4G-TP " << this->name_ << " is out of energy."
			<< std::endl;
		return;
	}
	std::string random_attack("");
	switch (rand() % 5) {
		case 0:
			random_attack = " knocks out " + target +
				" with his long and heavy ssh key";
			break;
		case 1:
			random_attack = " overtakes " + target
				+ " with multiple Norminette errors";
			break;
		case 2:
			random_attack = " beats " + target + " with a -42 flag";
			break;
		case 3:
			random_attack = " overwhelms " + target +
				" with a difficult cpp inheritance course";
			break;
		case 4:
			random_attack = ", with all this randomness, gets dizzy and attacks himself";
			break;
	}
	std::cout << "FR4G-TP " << this->name_
		<< random_attack << "!" << std::endl;
	this->energy_points_ -= 25;
	return;
}

void FragTrap::srand(void)
{
	static bool is_already_done = false;

	if (is_already_done == false) {
		::srand(time(0));
	}
	is_already_done = true;
	return;
}

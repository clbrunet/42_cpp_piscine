#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	:	hit_points_(100),
		max_hit_points_(100),
		energy_points_(50),
		max_energy_points_(50),
		level_(1),
		name_("Robby"),
		melee_attack_damage_(20),
		ranged_attack_damage_(15),
		armor_damage_reduction_(3)
{
	std::cout << "Hey everybody! Check out my package!" << std::endl;
	ScavTrap::srand();
	return;
}

ScavTrap::ScavTrap(std::string const& name)
	:	hit_points_(100),
		max_hit_points_(100),
		energy_points_(50),
		max_energy_points_(50),
		level_(1),
		name_(name),
		melee_attack_damage_(20),
		ranged_attack_damage_(15),
		armor_damage_reduction_(3)
{
	std::cout << "Hey everybody! Check out my package!" << std::endl;
	ScavTrap::srand();
	return;
}

ScavTrap::ScavTrap(ScavTrap const& src)
{
	std::cout << "Hey everybody! Check out my package!" << std::endl;
	*this = src;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Robot down!" << std::endl;
	return;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs)
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

void ScavTrap::rangedAttack(std::string const & target) const
{
	std::cout << "SC4V-TP " << this->name_ << " attacks " << target
		<< " at range, causing " << this->ranged_attack_damage_
		<< " points of damage!" << std::endl;
	return;
}

void ScavTrap::meleeAttack(std::string const & target) const
{
	std::cout << "SC4V-TP " << this->name_ << " attacks " << target
		<< " at close-range, causing " << this->melee_attack_damage_
		<< " points of damage!" << std::endl;
	return;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount < this->armor_damage_reduction_) {
		amount = 0;
	}
	else if (amount - this->armor_damage_reduction_ > this->hit_points_) {
		amount = this->hit_points_;
	}
	std::cout << "SC4V-TP " << this->name_ << " takes " << amount
		<< " points of damage!" << std::endl; 
	this->hit_points_ -= amount;
	return;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points_ + amount > this->max_hit_points_) {
		amount = this->max_hit_points_ - this->hit_points_;
	}
	std::cout << "SC4V-TP " << this->name_ << " gains " << amount
		<< " hit points!" << std::endl; 
	this->hit_points_ += amount;
	return;
}

void ScavTrap::challengeNewcomer(std::string const & target) const
{
	std::string random_challenge("");
	switch (rand() % 5) {
		case 0:
			random_challenge = ", with all this randomness, gets dizzy and chubby bunny challenges himself";
			break;
		case 1:
			random_challenge = " challenges " + target +
				" to eat a tablespoon of Tabasco";
			break;
		case 2:
			random_challenge = " challenges " + target
				+ " on the tennis court";
			break;
		case 3:
			random_challenge = " challenges " + target +
				" to a kitchen battle";
			break;
		case 4:
			random_challenge = " challenges " + target +
				" in a Mario Kart race";
			break;
	}
	std::cout << "SC4V-TP " << this->name_
		<< random_challenge << "!" << std::endl;
	return;
}

void ScavTrap::srand(void)
{
	static bool is_already_done = false;

	if (is_already_done == false) {
		::srand(time(0));
	}
	is_already_done = true;
	return;
}

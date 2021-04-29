#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	:	ClapTrap("SC4V-TP", 100, 100, 50, 50, 1, "Robby", 20, 15, 3)
{
	std::cout << "Hey everybody! Check out my package!" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string const& name)
	:	ClapTrap("SC4V-TP", 100, 100, 50, 50, 1, name, 20, 15, 3)
{
	std::cout << "Hey everybody! Check out my package!" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const& src)
	:	ClapTrap("FR4G-TP", src.hit_points_, src.max_hit_points_,
			src.energy_points_, src.max_energy_points_, src.level_, src.name_,
			src.melee_attack_damage_, src.ranged_attack_damage_,
			src.armor_damage_reduction_)
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

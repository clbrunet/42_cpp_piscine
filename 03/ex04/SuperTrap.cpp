#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void)
	:	ClapTrap(), FragTrap(), NinjaTrap()
{
	std::cout << "Let's get this party started!" << std::endl;
	return;
}

SuperTrap::SuperTrap(std::string const& name)
	:	ClapTrap("S8P3R-TP", 100, 100, 120, 120, 1, name, 60, 20, 5), FragTrap(), NinjaTrap()
{
	std::cout << "Let's get this party started!" << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap const& src)
	:	ClapTrap("S8P3R-TP", src.hit_points_, src.max_hit_points_,
			src.energy_points_, src.max_energy_points_, src.level_, src.name_,
			src.melee_attack_damage_, src.ranged_attack_damage_,
			src.armor_damage_reduction_)
{
	std::cout << "Let's get this party started!" << std::endl;
	*this = src;
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "You can't kill me!" << std::endl;
	return;
}

SuperTrap& SuperTrap::operator=(SuperTrap const& rhs)
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

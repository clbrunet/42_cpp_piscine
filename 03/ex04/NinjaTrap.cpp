#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
	:	ClapTrap()
{
	std::cout << "This time it'll be awesome, I promise!" << std::endl;
	return;
}

NinjaTrap::NinjaTrap(std::string const& name)
	:	ClapTrap("N1NJ4-TP", 60, 60, 120, 120, 1, name, 60, 5, 0)
{
	std::cout << "This time it'll be awesome, I promise!" << std::endl;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const& src)
	:	ClapTrap("N1NJ4-TP", src.hit_points_, src.max_hit_points_,
			src.energy_points_, src.max_energy_points_, src.level_, src.name_,
			src.melee_attack_damage_, src.ranged_attack_damage_,
			src.armor_damage_reduction_)
{
	std::cout << "This time it'll be awesome, I promise!" << std::endl;
	*this = src;
	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "Good thing I don't have a soul!" << std::endl;
	return;
}

NinjaTrap& NinjaTrap::operator=(NinjaTrap const& rhs)
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

void NinjaTrap::ninjaShoebox(NinjaTrap const& target) const
{
	std::cout << this->type_ << " " << this->name_
		<< " suggests a rock, paper, scissors duel to N1NJ4-TP " << target.name_
		<< "!" << std::endl;
	return;
}

void NinjaTrap::ninjaShoebox(FragTrap const& target) const
{
	std::cout << this->type_ << " " << this->name_ << " asks FR4G-TP "
		<< target.get_name() << " out!" << std::endl;
	return;
}

void NinjaTrap::ninjaShoebox(ScavTrap const& target) const
{
	std::cout << this->type_ << " " << this->name_
		<< " completely ignore SC4V-TP " << target.get_name() << "!"
		<< std::endl;
	return;
}

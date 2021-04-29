#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	:	ClapTrap()
{
	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	return;
}

FragTrap::FragTrap(std::string const& name)
	:	ClapTrap("FR4G-TP", 100, 100, 100, 100, 1, name, 30, 20, 5)
{
	std::cout << "Look out everybody! Things are about to get awesome!" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const& src)
	:	ClapTrap("FR4G-TP", src.hit_points_, src.max_hit_points_,
			src.energy_points_, src.max_energy_points_, src.level_, src.name_,
			src.melee_attack_damage_, src.ranged_attack_damage_,
			src.armor_damage_reduction_)
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

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->energy_points_ < 25) {
		std::cout << this->type_ << " " << this->name_ << " is out of energy."
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
	std::cout << this->type_ << " " << this->name_
		<< random_attack << "!" << std::endl;
	this->energy_points_ -= 25;
	return;
}

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap base class created." << std::endl;
	ClapTrap::srand();
	return;
}

ClapTrap::ClapTrap(std::string type, unsigned int hit_points,
			unsigned int max_hit_points, unsigned int energy_points,
			unsigned int max_energy_points, unsigned int level,
			std::string const& name, unsigned int melee_attack_damage,
			unsigned int ranged_attack_damage,
			unsigned int armor_damage_reduction)
	:	hit_points_(hit_points),
		max_hit_points_(max_hit_points),
		energy_points_(energy_points),
		max_energy_points_(max_energy_points),
		level_(level),
		name_(name),
		melee_attack_damage_(melee_attack_damage),
		ranged_attack_damage_(ranged_attack_damage),
		armor_damage_reduction_(armor_damage_reduction),
		type_(type)
{
	std::cout << "ClapTrap base class created." << std::endl;
	ClapTrap::srand();
	return;
}

ClapTrap::ClapTrap(ClapTrap const& src)
{
	std::cout << "ClapTrap base class created." << std::endl;
	*this = src;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap base class destruction." << std::endl;
	return;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs)
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
	this->type_ = rhs.type_;
	return *this;
}

void ClapTrap::rangedAttack(std::string const & target) const
{
	std::cout << this->type_ << " " << this->name_ << " attacks " << target
		<< " at range, causing " << this->ranged_attack_damage_
		<< " points of damage!" << std::endl;
	return;
}

void ClapTrap::meleeAttack(std::string const & target) const
{
	std::cout << this->type_ << " " << this->name_ << " attacks " << target
		<< " at close-range, causing " << this->melee_attack_damage_
		<< " points of damage!" << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount < this->armor_damage_reduction_) {
		amount = 0;
	}
	else if (amount - this->armor_damage_reduction_ > this->hit_points_) {
		amount = this->hit_points_;
	}
	std::cout << this->type_ << " " << this->name_ << " takes " << amount
		<< " points of damage!" << std::endl; 
	this->hit_points_ -= amount;
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points_ + amount > this->max_hit_points_) {
		amount = this->max_hit_points_ - this->hit_points_;
	}
	std::cout << this->type_ << " " << this->name_ << " gains " << amount
		<< " hit points!" << std::endl; 
	this->hit_points_ += amount;
	return;
}
std::string const& ClapTrap::get_name(void) const
{
	return this->name_;
}

void ClapTrap::srand(void)
{
	static bool is_already_done = false;

	if (is_already_done == false) {
		::srand(time(0));
	}
	is_already_done = true;
	return;
}

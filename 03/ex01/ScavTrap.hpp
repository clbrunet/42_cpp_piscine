#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

class ScavTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string const& name);
	ScavTrap(ScavTrap const& src);
	~ScavTrap(void);

	ScavTrap& operator=(ScavTrap const& rhs);

	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void challengeNewcomer(std::string const & target) const;

private:
	unsigned int hit_points_;
	unsigned int max_hit_points_;
	unsigned int energy_points_;
	unsigned int max_energy_points_;
	unsigned int level_;
	std::string name_;
	unsigned int melee_attack_damage_;
	unsigned int ranged_attack_damage_;
	unsigned int armor_damage_reduction_;

	static void srand(void);
};

#endif

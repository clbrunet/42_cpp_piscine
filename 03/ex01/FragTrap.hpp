#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

class FragTrap
{
public:
	FragTrap(void);
	FragTrap(std::string const& name);
	FragTrap(FragTrap const& src);
	~FragTrap(void);

	FragTrap& operator=(FragTrap const& rhs);

	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void vaulthunter_dot_exe(std::string const & target);

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

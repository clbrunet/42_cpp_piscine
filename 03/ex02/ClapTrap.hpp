#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

class ClapTrap
{
public:
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	ClapTrap(void);
	ClapTrap(std::string type, unsigned int hit_points,
			unsigned int max_hit_points, unsigned int energy_points,
			unsigned int max_energy_points, unsigned int level,
			std::string const& name, unsigned int melee_attack_damage,
			unsigned int ranged_attack_damage,
			unsigned int armor_damage_reduction);
	ClapTrap(ClapTrap const& src);
	~ClapTrap(void);

	ClapTrap& operator=(ClapTrap const& rhs);

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

private:
	std::string type_;
};

#endif

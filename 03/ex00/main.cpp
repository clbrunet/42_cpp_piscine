#include "FragTrap.hpp"

int main(void)
{
	FragTrap robot("Mike");

	std::cout << "\n";
	robot.meleeAttack("Marcus");
	robot.rangedAttack("Jessica");
	std::cout << "\n";
	robot.takeDamage(999);
	robot.beRepaired(999);
	std::cout << "\n";
	robot.vaulthunter_dot_exe("Jack");
	robot.vaulthunter_dot_exe("Anne");
	robot.vaulthunter_dot_exe("Victor");
	robot.vaulthunter_dot_exe("Lara");
	robot.vaulthunter_dot_exe("SHOULD NOT BE DISPLAYED");
	std::cout << "\n";
}

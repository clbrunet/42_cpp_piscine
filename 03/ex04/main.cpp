#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

void FragTrap_tests(void)
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

void ScavTrap_tests(void)
{
	ScavTrap robot("Mike");
	std::cout << "\n";
	robot.meleeAttack("Marcus");
	robot.rangedAttack("Jessica");
	std::cout << "\n";
	robot.takeDamage(999);
	robot.beRepaired(999);
	std::cout << "\n";
	robot.challengeNewcomer("Jack");
	robot.challengeNewcomer("Victor");
	robot.challengeNewcomer("Lara");
	std::cout << "\n";
}

void NinjaTrap_tests(void)
{
	NinjaTrap robot("Mike");
	std::cout << "\n";
	robot.meleeAttack("Marcus");
	robot.rangedAttack("Jessica");
	std::cout << "\n";
	robot.takeDamage(999);
	robot.beRepaired(999);
	std::cout << "\n";
	robot.ninjaShoebox(FragTrap("Jack"));
	robot.ninjaShoebox(ScavTrap("Victor"));
	robot.ninjaShoebox(NinjaTrap("Lara"));
	std::cout << "\n";
}

void SuperTrap_tests(void)
{
	SuperTrap robot("Mike");
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
	robot.ninjaShoebox(FragTrap("Jack"));
	robot.ninjaShoebox(ScavTrap("Victor"));
	robot.ninjaShoebox(NinjaTrap("Lara"));
	std::cout << "\n";
}

int main(void)
{
	std::cout << "FragTrap tests\n\n";
	FragTrap_tests();
	std::cout << "\n--------------------------------------------------\n\n";
	std::cout << "ScavTrap tests\n\n";
	ScavTrap_tests();
	std::cout << "\n--------------------------------------------------\n\n";
	std::cout << "NinjaTrap tests\n\n";
	NinjaTrap_tests();
	std::cout << "\n--------------------------------------------------\n\n";
	std::cout << "SuperTrap tests\n\n";
	SuperTrap_tests();
}

#include <iostream>

#include "Human.hpp"

void	Human::meleeAttack(std::string const & target)
{
	std::cout << "Melee attack on " << target << "." << std::endl;
	return;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "Ranged attack on " << target << "." << std::endl;
	return;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "Intimidating shout on " << target << "." << std::endl;
	return;
}

void	Human::action(std::string const & action_name, std::string const & target)
{
	Human_action	actions[3] =
	{ &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout };
	std::string	actions_names[3] =
	{ "meleeAttack", "rangedAttack", "intimidatingShout" };

	for (int i = 0; i < 3; i++) {
		if (actions_names[i] == action_name)
			return ((this->*actions[i])(target));
	}
	std::cout << "Action : '" << action_name << "' doesn't exist." << std::endl;
	return;
}

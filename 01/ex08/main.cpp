#include "Human.hpp"

int	main(void)
{
	Human	human;

	human.action("unknownAction", "unknown target");
	human.action("meleeAttack", "close enemy");
	human.action("rangedAttack", "far enemy");
	human.action("intimidatingShout", "someone who doesn't deserve it");
    return 0;
}

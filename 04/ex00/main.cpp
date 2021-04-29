#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "HouseElf.hpp"

// int main(void)
// {
// 	Sorcerer robert("Robert", "the Magnificent");
// 	Victim jim("Jimmy");
// 	Peon joe("Joe");
// 	std::cout << robert << jim << joe;
// 	robert.polymorph(jim);
// 	robert.polymorph(joe);
// 	return 0;
// }

int main(void)
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	HouseElf john("John");
	std::cout << robert << jim << joe << john;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(john);
	return 0;
}

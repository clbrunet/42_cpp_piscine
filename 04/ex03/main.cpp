#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

int main()
{
	std::cout << "Base :\n" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* zero;
	zero = src->createMateria("ice");
	me->equip(zero);
	AMateria* tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "\n\nPlay with use and unequip :\n" << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(3, *bob);
	me->unequip(3);
	delete tmp;
	me->use(3, *bob);
	me->use(42, *bob);
	me->use(-1, *bob);
	me->use(-42, *bob);
	me->unequip(-1);
	me->unequip(-42);
	me->unequip(42);
	me->unequip(3);
	std::cout << "\n\nCheck unequip :\n" << std::endl;
	me->use(0, *bob);
	me->unequip(0);
	delete zero;
	me->use(0, *bob);
	std::cout << "\n\nTry getXP :\n" << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << "XP: " << tmp->getXP() << std::endl;
	me->use(3, *bob);
	std::cout << "XP: " << tmp->getXP() << std::endl;
	me->use(3, *bob);
	std::cout << "XP: " << tmp->getXP() << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}

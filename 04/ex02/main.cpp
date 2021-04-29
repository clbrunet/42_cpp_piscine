#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

/*
int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	return 0;
}
*/

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	Squad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << "\ngetCount" << std::endl;
	std::cout << vlc->getCount() << std::endl;
	vlc->push(jim);
	vlc->push(NULL);
	std::cout << vlc->getCount() << std::endl;
	std::cout << "\ngetUnit" << std::endl;
	std::cout << vlc->getUnit(-1) << std::endl;
	std::cout << vlc->getUnit(0) << std::endl;
	std::cout << vlc->getUnit(1) << std::endl;
	std::cout << vlc->getUnit(2) << std::endl;
	std::cout << "\nCopy constructor" << std::endl;
	ISquad* dcp = new Squad(*vlc);
	std::cout << "src: " << vlc->getCount() << vlc->getUnit(0) << std::endl;
	std::cout << "dcp: " << dcp->getCount() << dcp->getUnit(0) << std::endl;
	delete vlc;
	delete dcp;
	return 0;
}

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	return;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine* TacticalMarine::clone() const
{
	return new TacticalMarine(*this);
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
	std::cout <<  "* attacks with a chainsword *" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const& src)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	(void)src;
	return;
}

TacticalMarine& TacticalMarine::operator=(TacticalMarine const& rhs)
{
	(void)rhs;
	return *this;
}

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
	return;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator* AssaultTerminator::clone() const
{
	return new AssaultTerminator(*this);
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
	std::cout <<  "* attacks with chainfists *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const& src)
{
	std::cout << "* teleports from space *" << std::endl;
	(void)src;
	return;
}

AssaultTerminator& AssaultTerminator::operator=(AssaultTerminator const& rhs)
{
	(void)rhs;
	return *this;
}

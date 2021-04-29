#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include <iostream>

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	virtual ~TacticalMarine();
	TacticalMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;

private:
	TacticalMarine(TacticalMarine const& src);
	TacticalMarine& operator=(TacticalMarine const& rhs);
};

#endif

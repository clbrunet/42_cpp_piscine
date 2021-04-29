#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <stdlib.h>

#include "ISquad.hpp"

class Squad : public ISquad
{
public:
	Squad();
	Squad(Squad const& src);
	virtual ~Squad();
	Squad& operator=(Squad const& rhs);
	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine*);

private:
	int count_;
	ISpaceMarine** units_;
};

#endif

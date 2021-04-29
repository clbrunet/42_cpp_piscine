#ifndef STRIPMINER_HPP
#define STRIPMINER_HPP

#include <iostream>

#include "IMiningLaser.hpp"

class IAsteroid;

class StripMiner : public IMiningLaser
{
public:
	StripMiner();
	virtual ~StripMiner();
	virtual void mine(IAsteroid*);

private:
	StripMiner(StripMiner const& src);
	StripMiner& operator=(StripMiner const& rhs);
};

#endif

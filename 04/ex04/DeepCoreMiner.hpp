#ifndef DEEPCOREMINER_HPP
#define DEEPCOREMINER_HPP

#include <iostream>

#include "IMiningLaser.hpp"

class IAsteroid;

class DeepCoreMiner : public IMiningLaser
{
public:
	DeepCoreMiner();
	virtual ~DeepCoreMiner();
	virtual void mine(IAsteroid*);

private:
	DeepCoreMiner(DeepCoreMiner const& src);
	DeepCoreMiner& operator=(DeepCoreMiner const& rhs);
};

#endif

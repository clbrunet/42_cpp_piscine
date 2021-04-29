#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <iostream>

#include "IAsteroid.hpp"

class Asteroid : public IAsteroid
{
public:
	Asteroid();
	virtual ~Asteroid();
	virtual std::string beMined(DeepCoreMiner*) const;
	virtual std::string beMined(StripMiner*) const;
	std::string getName() const;

private:
	static std::string const name_;

	Asteroid(Asteroid const& src);
	Asteroid& operator=(Asteroid const& rhs);
};

#endif

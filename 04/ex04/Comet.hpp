#ifndef COMET_HPP
# define COMET_HPP

#include <iostream>

#include "IAsteroid.hpp"

class Comet : public IAsteroid
{
public:
	Comet();
	virtual ~Comet();
	virtual std::string beMined(DeepCoreMiner*) const;
	virtual std::string beMined(StripMiner*) const;
	std::string getName() const;

private:
	static std::string const name_;

	Comet(Comet const& src);
	Comet& operator=(Comet const& rhs);
};

#endif

#include "Asteroid.hpp"

Asteroid::Asteroid()
{
	return;
}

Asteroid::~Asteroid()
{
	return;
}

std::string Asteroid::beMined(DeepCoreMiner* miner) const
{
	(void)miner;
	return "Dragonite";
}

std::string Asteroid::beMined(StripMiner* miner) const
{
	(void)miner;
	return "Flavium";
}

std::string Asteroid::getName() const
{
	return Asteroid::name_;
}

std::string const Asteroid::name_ = "Asteroid";

Asteroid::Asteroid(Asteroid const& src)
{
	*this = src;
	return;
}

Asteroid& Asteroid::operator=(Asteroid const& rhs)
{
	(void)rhs;
	return *this;
}

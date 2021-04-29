#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "IAsteroid.hpp"

StripMiner::StripMiner()
{
	return;
}

StripMiner::~StripMiner()
{
	return;
}

void StripMiner::mine(IAsteroid* asteroid)
{
	std::cout << "* strip mining... got " << asteroid->beMined(this) << "! *" << std::endl;
}

StripMiner::StripMiner(StripMiner const& src)
{
	*this = src;
	return;
}

StripMiner& StripMiner::operator=(StripMiner const& rhs)
{
	(void)rhs;
	return *this;
}

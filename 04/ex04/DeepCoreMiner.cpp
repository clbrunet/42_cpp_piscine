#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"

DeepCoreMiner::DeepCoreMiner()
{
	return;
}

DeepCoreMiner::~DeepCoreMiner()
{
	return;
}

void DeepCoreMiner::mine(IAsteroid* asteroid)
{
	std::cout << "* mining deep... got " << asteroid->beMined(this) << "! *" << std::endl;
}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const& src)
{
	*this = src;
	return;
}

DeepCoreMiner& DeepCoreMiner::operator=(DeepCoreMiner const& rhs)
{
	(void)rhs;
	return *this;
}

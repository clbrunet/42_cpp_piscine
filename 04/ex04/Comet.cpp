#include "Comet.hpp"

Comet::Comet()
{
	return;
}

Comet::~Comet()
{
	return;
}

std::string Comet::beMined(DeepCoreMiner* miner) const
{
	(void)miner;
	return "Meium";
}

std::string Comet::beMined(StripMiner* miner) const
{
	(void)miner;
	return "Tartarite";
}

std::string Comet::getName() const
{
	return Comet::name_;
}

std::string const Comet::name_ = "Comet";

Comet::Comet(Comet const& src)
{
	*this = src;
	return;
}

Comet& Comet::operator=(Comet const& rhs)
{
	(void)rhs;
	return *this;
}

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void)
	:	Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::RadScorpion(RadScorpion const& src)
{
	*this = src;
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
	return;
}

RadScorpion& RadScorpion::operator=(RadScorpion const& rhs)
{
	this->hp_ = rhs.hp_;
	this->type_ = rhs.type_;
	return *this;
}

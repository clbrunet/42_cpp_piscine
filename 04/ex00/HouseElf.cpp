#include "HouseElf.hpp"

HouseElf::HouseElf(std::string name)
	:	Victim(name)
{
	std::cout << "Hello." << std::endl;
	return;
}

HouseElf::HouseElf(Victim const& src)
{
	*this = src;
	std::cout << "Hello." << std::endl;
	return;
}

HouseElf::~HouseElf(void)
{
	std::cout << "Bye..." << std::endl;
	return;
}

HouseElf& HouseElf::operator=(HouseElf const& src)
{
	this->name_ = src.name_;
	return *this;
}

void HouseElf::getPolymorphed(void) const
{
	std::cout << this->name_
		<< " has been turned into a banana!" << std::endl;
}

HouseElf::HouseElf(void)
	:	Victim()
{
	return;
}

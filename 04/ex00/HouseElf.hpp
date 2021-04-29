#ifndef HOUSEELF_HPP
# define HOUSEELF_HPP

#include <iostream>

#include "Victim.hpp"

class HouseElf : public Victim
{
public:
	HouseElf(std::string name);
	HouseElf(Victim const& src);
	~HouseElf(void);
	HouseElf& operator=(HouseElf const& src);

	virtual void getPolymorphed(void) const;

private:
	HouseElf(void);
};

#endif

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <string>
#include <iostream>

class Victim
{
public:
	Victim(std::string name);
	Victim(Victim const& src);
	~Victim(void);
	Victim& operator=(Victim const& rhs);

	std::string name(void) const;

	virtual void getPolymorphed(void) const;

protected:
	Victim(void);

	std::string name_;
};

std::ostream& operator<<(std::ostream& ostream, Victim const& rhs);

#endif

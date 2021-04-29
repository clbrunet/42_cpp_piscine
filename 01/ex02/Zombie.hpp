#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
public:
	Zombie(std::string type, std::string name);
	~Zombie(void);

	void	announce(void);

private:
	std::string	type_;
	std::string	name_;
};

#endif

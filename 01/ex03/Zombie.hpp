#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
public:
	Zombie(void);
	Zombie(std::string type, std::string name);
	~Zombie(void);

    void	fill(std::string type, std::string name);
	void	announce(void);

private:
	std::string	type_;
	std::string	name_;
};

#endif

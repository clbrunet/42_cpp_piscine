#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony {
public:
	Pony(std::string name, std::string color);
	~Pony(void);

	void	describe(void);

private:
	std::string	name_;
	std::string	color_;
};

#endif

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class Form;

class Intern
{
public:
	Intern();
	virtual ~Intern();

	Form* makeForm(std::string const& form_name, std::string const& target)
		const;

private:
	Intern(Intern const& src);
	Intern& operator=(Intern const& rhs);
};

#endif

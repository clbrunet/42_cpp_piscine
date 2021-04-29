#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	return;
}

Intern::~Intern()
{
	return;
}

Form* Intern::makeForm(std::string const& form_name, std::string const& target)
	const
{
	Form* forms[3] = { new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target), new PresidentialPardonForm(target) };
	std::string const form_names[3] = { forms[0]->getName(), forms[1]->getName(),
		forms[2]->getName() };
	Form* form = NULL;
	for (int i = 0; i < 3; i++) {
		if (form_name == form_names[i]) {
			form = forms[i];
			std::cout << "Intern creates " << form_name << std::endl;
		}
		else {
			delete forms[i];
		}
	}
	if (form == NULL) {
		std::cout << form_name << " does not exist" << std::endl;
	}
	return form;
}

Intern::Intern(Intern const& src)
{
	(void)src;
	return;
}
Intern& Intern::operator=(Intern const& rhs)
{
	(void)rhs;
	return *this;
}

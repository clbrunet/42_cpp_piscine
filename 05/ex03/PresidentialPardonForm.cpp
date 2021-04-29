#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	:	Form("presidential pardon", 25, 5, target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src)
	:	Form(src)
{
	*this = src;
	return;
}

PresidentialPardonForm&
PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	this->Form::operator=(rhs);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkForm(executor);
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox"
		<< std::endl;
}

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	:	Form("RobotomyRequest", 72, 45, target)
{
	RobotomyRequestForm::srand();
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
	:	Form(src)
{
	*this = src;
	return;
}

RobotomyRequestForm&
RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	this->Form::operator=(rhs);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkForm(executor);
	std::cout << "DRdRDRdRRdrdrdrdRdrrrrriiillll" << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	}
	else {
		std::cout << this->getTarget() << " robotomization is a failure" << std::endl;
	}
}

void RobotomyRequestForm::srand(void)
{
	static bool is_already_done = false;

	if (is_already_done == false) {
		std::srand(time(0));
		is_already_done = true;
	}
	return;
}

#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void previous_tests()
{
	try
	{
		Bureaucrat allan("Allan", HIGHEST_GRADE - 1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat allan("Allan", HIGHEST_GRADE);
		std::cout << allan << std::endl;
		allan.riseUp();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat allan("Allan", LOWEST_GRADE + 1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat allan("Allan", LOWEST_GRADE);
		std::cout << allan << std::endl;
		allan.riseDown();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void new_tests()
{
	ShrubberyCreationForm shrubbery_creation("Tim");
	RobotomyRequestForm robotomy_request("Robin");
	PresidentialPardonForm presidential_pardon("Jake");
	std::cout << shrubbery_creation << std::endl;
	std::cout << robotomy_request << std::endl;
	std::cout << presidential_pardon << std::endl;
	std::cout << std::endl;
	Bureaucrat allan("Allan", HIGHEST_GRADE);
	try
	{
		shrubbery_creation.checkForm(allan);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	allan.signForm(shrubbery_creation);
	try
	{
		Bureaucrat lame("LameMan", LOWEST_GRADE);
		shrubbery_creation.checkForm(lame);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		robotomy_request.beSigned(allan);
		presidential_pardon.beSigned(allan);
		shrubbery_creation.execute(allan);
		robotomy_request.execute(allan);
		robotomy_request.execute(allan);
		robotomy_request.execute(allan);
		presidential_pardon.execute(allan);
	}
	catch (std::exception * e)
	{
		std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
	}
	std::cout << std::endl;
	std::cout << allan << std::endl;
	for (int i = 0; i < 4; i++) {
		allan.riseDown();
	}
	std::cout << allan << std::endl;
	allan.executeForm(presidential_pardon);
	allan.riseDown();
	std::cout << allan << std::endl;
	allan.executeForm(presidential_pardon);
}

int main()
{
	std::cout << "Previous tests\n" << std::endl;
	previous_tests();
	std::cout << "\n========================================\n" << std::endl;
	std::cout << "New tests\n" << std::endl;
	new_tests();
}

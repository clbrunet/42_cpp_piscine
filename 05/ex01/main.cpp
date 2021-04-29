#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
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
	try
	{
		Form form("Pay stub", 75, HIGHEST_GRADE - 1);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form("Pay stub", HIGHEST_GRADE - 1, 75);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form("Pay stub", 75, LOWEST_GRADE + 1);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form("Pay stub", LOWEST_GRADE + 1, 75);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form("Pay stub", 75, 75);
		Bureaucrat allan("Allan", LOWEST_GRADE);
		form.beSigned(allan);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form form("Pay stub", 75, 75);
		Bureaucrat allan("Allan", 75 + 1);
		allan.signForm(form);
		allan.riseUp();
		allan.signForm(form);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

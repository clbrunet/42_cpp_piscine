#include <iostream>

#include "Bureaucrat.hpp"

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
		std::cout << allan;
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
		std::cout << allan;
		allan.riseDown();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

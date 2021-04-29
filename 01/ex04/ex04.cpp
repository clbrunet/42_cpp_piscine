#include <iostream>

int	main(void)
{
	std::string	original = "HI THIS IS BRAIN";

	std::string	*pointer = &original;
	std::string	&reference = original;

	std::cout << "With pointer :" << std::endl;
	std::cout << *pointer << std::endl;
	std::cout << std::endl;
	std::cout << "With reference :" << std::endl;
	std::cout << reference << std::endl;
}

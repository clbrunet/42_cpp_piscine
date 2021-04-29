#include <cstdlib>
#include <iostream>

#include "phonebook.hpp"

int	main(void)
{
	phonebook	phonebook;

	std::string	input = "";
	do {
		std::cout << "phonebook > ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			phonebook.add_contact();
		}
		else if (input == "SEARCH") {
			phonebook.search_contact();
		}
	} while (input != "EXIT" && !std::cin.eof());
	if (std::cin.eof())
		std::cout << std::endl;
	return (0);
}

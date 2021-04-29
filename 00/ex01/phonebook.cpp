#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "phonebook.hpp"

phonebook::phonebook(void)
	:	nb_contacts_(0)
{
	std::cout << "My Awesome PhoneBook" << std::endl << std::endl;
	return;
}

void	phonebook::add_contact(void)
{
	if (this->nb_contacts_ + 1 > 8) {
		std::cout << "The phonebook cannot store more than 8 contacts" << std::endl;
		return;
	}
	this->contacts_[this->nb_contacts_].fill();
	this->nb_contacts_++;
	return;
}

static std::string	truncate_field(std::string str, size_t width)
{
	if (str.length() > width) {
		str = str.substr(0, width - 1) + ".";
	}
	return (str);
}

void	phonebook::display_contacts_list(void) const
{
	std::cout << "=============================================" << std::endl;
	std::cout << "|"
		<< std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << "|"
		<< std::endl;
	std::cout << "=============================================" << std::endl;
	for (int i = 0; i < this->nb_contacts_; i++) {
		std::cout << "|"
			<< std::setw(10) << i + 1 << "|"
			<< std::setw(10) << truncate_field(this->contacts_[i].get_first_name(), 10) << "|"
			<< std::setw(10) << truncate_field(this->contacts_[i].get_last_name(), 10) << "|"
			<< std::setw(10) << truncate_field(this->contacts_[i].get_nickname(), 10) << "|"
			<< std::endl;
		if (i + 1 < this->nb_contacts_) {
			std::cout << "|----------+----------+----------+----------|" << std::endl;
		}
	}
	std::cout << "=============================================" << std::endl;
}

static int	getnumber(void)
{
	std::string	input = "";
	std::getline(std::cin, input);
	char const	*c_input = input.c_str();
	while (isspace(*c_input))
		c_input++;
	while (std::isdigit(*c_input))
		c_input++;
	while (isspace(*c_input))
		c_input++;
	if (*c_input)
		return (0);
	return (atoi(input.c_str()));
}

void	phonebook::display_contact_info(void) const
{
	std::cout << "Select an index > ";
	int index = getnumber();
	while (!std::cin.eof() && (index < 1 || this->nb_contacts_ < index)) {
		std::cout << "Select a correct index (between 1 and "
			<< this->nb_contacts_ << ") > ";
		index = getnumber();
	}
	if (!std::cin.eof())
		this->contacts_[index - 1].describe();
}

void	phonebook::search_contact(void) const
{
	if (this->nb_contacts_ == 0) {
		std::cout << "No contact found" << std::endl;
		return;
	}
	display_contacts_list();
	display_contact_info();
	return;
}

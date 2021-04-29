#include <iostream>

#include "contact.hpp"

contact::contact(void)
	:	first_name_(""),
		last_name_(""),
		nickname_(""),
		login_(""),
		postal_address_(""),
		email_address_(""),
		phone_number_(""),
		birthday_date_(""),
		favorite_meal_(""),
		underwear_color_(""),
		darkest_secret_("")
{
	return;
}

void	contact::fill(void)
{
	std::cout << "Contact first name > ";
	std::getline(std::cin, this->first_name_);
	if (std::cin.eof())
		return;
	std::cout << "Contact last name > ";
	std::getline(std::cin, this->last_name_);
	if (std::cin.eof())
		return;
	std::cout << "Contact nickname > ";
	std::getline(std::cin, this->nickname_);
	if (std::cin.eof())
		return;
	std::cout << "Contact login > ";
	std::getline(std::cin, this->login_);
	if (std::cin.eof())
		return;
	std::cout << "Contact postal address > ";
	std::getline(std::cin, this->postal_address_);
	if (std::cin.eof())
		return;
	std::cout << "Contact email address > ";
	std::getline(std::cin, this->email_address_);
	if (std::cin.eof())
		return;
	std::cout << "Contact phone number > ";
	std::getline(std::cin, this->phone_number_);
	if (std::cin.eof())
		return;
	std::cout << "Contact birthday date > ";
	std::getline(std::cin, this->birthday_date_);
	if (std::cin.eof())
		return;
	std::cout << "Contact favorite meal > ";
	std::getline(std::cin, this->favorite_meal_);
	if (std::cin.eof())
		return;
	std::cout << "Contact underwear color > ";
	std::getline(std::cin, this->underwear_color_);
	if (std::cin.eof())
		return;
	std::cout << "Contact darkest secret > ";
	std::getline(std::cin, this->darkest_secret_);
}

void	contact::describe(void) const
{
	std::cout << "First name : "<< this->first_name_ << std::endl;
	std::cout << "Last name : " << this->last_name_ << std::endl;
	std::cout << "Nickname : " << this->nickname_ << std::endl;
	std::cout << "Login : " << this->login_ << std::endl;
	std::cout << "Postal address : " << this->postal_address_ << std::endl;
	std::cout << "Email address : " << this->email_address_ << std::endl;
	std::cout << "Phone number : " << this->phone_number_ << std::endl;
	std::cout << "Birthday date : " << this->birthday_date_ << std::endl;
	std::cout << "Favorite meal : " << this->favorite_meal_ << std::endl;
	std::cout << "Underwear color : " << this->underwear_color_ << std::endl;
	std::cout << "Darkest secret : " << this->darkest_secret_ << std::endl;
}

std::string	contact::get_first_name(void) const
{
	return (this->first_name_);
}

std::string	contact::get_last_name(void) const
{
	return (this->last_name_);
}

std::string	contact::get_nickname(void) const
{
	return (this->nickname_);
}

std::string	contact::get_login(void) const
{
	return (this->login_);
}

std::string	contact::get_postal_address(void) const
{
	return (this->postal_address_);
}

std::string	contact::get_email_address(void) const
{
	return (this->email_address_);
}

std::string	contact::get_phone_number(void) const
{
	return (this->phone_number_);
}

std::string	contact::get_birthday_date(void) const
{
	return (this->birthday_date_);
}

std::string	contact::get_favorite_meal(void) const
{
	return (this->favorite_meal_);
}

std::string	contact::get_underwear_color(void) const
{
	return (this->underwear_color_);
}

std::string	contact::get_darkest_secret(void) const
{
	return (this->darkest_secret_);
}

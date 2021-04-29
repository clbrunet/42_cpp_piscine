#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class contact {
public:
	contact(void);

	void	fill(void);
	void	describe(void) const;

	std::string	get_first_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
	std::string	get_login(void) const;
	std::string	get_postal_address(void) const;
	std::string	get_email_address(void) const;
	std::string	get_phone_number(void) const;
	std::string	get_birthday_date(void) const;
	std::string	get_favorite_meal(void) const;
	std::string	get_underwear_color(void) const;
	std::string	get_darkest_secret(void) const;

private:
	std::string	first_name_;
	std::string	last_name_;
	std::string	nickname_;
	std::string	login_;
	std::string	postal_address_;
	std::string	email_address_;
	std::string	phone_number_;
	std::string	birthday_date_;
	std::string	favorite_meal_;
	std::string	underwear_color_;
	std::string	darkest_secret_;
};

#endif

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class phonebook {
public:
	phonebook(void);

	void	add_contact(void);
	void	search_contact(void) const;

private:
	contact	contacts_[8];
	int		nb_contacts_;

	void	display_contacts_list(void) const;
	void	display_contact_info(void) const;
};

#endif

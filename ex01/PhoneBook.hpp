#ifndef EX01_PHONEBOOK_HPP
# define EX01_PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);
	PhoneBook(const PhoneBook &book);
	PhoneBook		&operator=(const PhoneBook &book);
	bool			AddContact(const Contact &contact);
	const Contact	&GetContact(int index) const;

	static const Contact	invalidContact;
private:
	void					_Copy(const PhoneBook &book);
	unsigned short			_Count(void) const;
	Contact					_contacts[8];
	unsigned short			_head;
	unsigned short			_tail;
};
#endif

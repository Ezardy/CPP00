#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

void		search_contact(const PhoneBook &book);
std::string	fitted_string(const std::string &str);
void		add_contact(PhoneBook &book);
bool		set_field(Contact &contact,
				bool (Contact::*setter)(const std::string &),
				const std::string name);
void		print_help(void);

int	main() {
	PhoneBook	book;
	bool		running = true;
	std::string	command;

	while (running) {
		std::cout << "> ";
		std::cin >> command;
		if (command == "EXIT")
			running = false;
		else if (command == "SEARCH") {
			search_contact(book);
		} else if (command == "ADD") {
			add_contact(book);
		} else
			print_help();
	}
	return 0;
}

void	search_contact(const PhoneBook &book) {
	int	i;

	std::cout << "Contact's index (0-7): ";
	std::cin >> i;
	const Contact	&contact = book.GetContact(i);
	if (contact.IsInvalid())
		std::cerr << "Invalid contact's index" << std::endl;
	else
		std::cout << std::setw(10) << i
			<< '|' << std::setw(10) << fitted_string(contact.FirstName())
			<< '|' << std::setw(10) << fitted_string(contact.LastName())
			<< '|' << std::setw(10) << fitted_string(contact.NickName())
			<< std::endl;
}

std::string	fitted_string(const std::string &str) {
	std::string	substr;
	if (str.length() > 10) {
		substr = str.substr(0, 10);
		substr[9] = '.';
	} else
		substr = str;
	return substr;
}

void	add_contact(PhoneBook &book) {
	static Contact	contact;

	if (!(set_field(contact, &Contact::SetFirstName, "First name")
			&& set_field(contact, &Contact::SetLastName, "Last name")
			&& set_field(contact, &Contact::SetNickName, "Nickname")
			&& set_field(contact, &Contact::SetPhoneNumber, "Phone number")
			&& set_field(contact, &Contact::SetDarkestSecret, "Darkest secret")
			&& book.AddContact(contact)))
		std::cerr << "The contact is invalid" << std::endl;
}

bool	set_field(Contact &contact,
			bool (Contact::*setter)(const std::string &),
			const std::string name) {
	std::string	str;

	std::cout << name << ": ";
	std::cin >> str;
	return (contact.*setter)(str);
}

void	print_help(void) {
	std::cout << "Commands: ADD SEARCH EXIT" << std::endl << std::endl;
}

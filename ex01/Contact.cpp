#include <cctype>

#include "Contact.hpp"

Contact::Contact(void) {

}

Contact::~Contact(void) {

}

Contact::Contact(const Contact &contact) {
	_Copy(contact);
}

Contact	&Contact::operator=(const Contact &contact) {
	_Copy(contact);
	return *this;
}

Contact::Contact(const std::string &firstName, const std::string &lastName,
			const std::string &nickName, const std::string &phoneNumber,
			const std::string &darkestSecret) {
	SetFirstName(firstName);
	SetLastName(lastName);
	SetNickName(nickName);
	SetPhoneNumber(phoneNumber);
	SetDarkestSecret(darkestSecret);
}

const std::string	&Contact::FirstName(void) const {
	return _firstName;
}

const std::string	&Contact::LastName(void) const {
	return _lastName;
}

const std::string	&Contact::NickName(void) const {
	return _nickName;
}

const std::string	&Contact::PhoneNumber(void) const {
	return _phoneNumber;
}

const std::string	&Contact::DarkestSecret(void) const {
	return _darkestSecret;
}

bool	Contact::IsInvalid(void) const {
	return _firstName.empty() || _lastName.empty() || _nickName.empty()
		|| _phoneNumber.empty() || _darkestSecret.empty();
}

bool	Contact::SetFirstName(const std::string &name) {
	return _SetFieldAlpha(&Contact::_firstName, name);
}

bool	Contact::SetLastName(const std::string &name) {
	return _SetFieldAlpha(&Contact::_lastName, name);
}

bool	Contact::SetNickName(const std::string &name) {
	return _SetFieldAlpha(&Contact::_nickName, name);
}

bool	Contact::SetPhoneNumber(const std::string &number) {
	return _SetFieldNum(&Contact::_phoneNumber, number);
}

bool	Contact::SetDarkestSecret(const std::string &secret) {
	return _SetFieldNonEmpty(&Contact::_darkestSecret, secret);
}

void	Contact::_Copy(const Contact &contact) {
	_firstName = contact._firstName;
	_lastName = contact._lastName;
	_nickName = contact._nickName;
	_phoneNumber = contact._phoneNumber;
	_darkestSecret = contact._darkestSecret;
}

bool	Contact::_SetFieldNonEmpty(std::string Contact::*field,
			const std::string &str) {
	bool	set;

	if ((set = !str.empty()))
		this->*field = str;
	return set;
}

bool	Contact::_SetFieldAlpha(std::string Contact::*field,
			const std::string &str) {
	bool	set;

	if (str.empty())
		set = false;
	else {
		std::string::const_iterator	i;
		for (i = str.begin(); i != str.end() && std::isalpha(*i); i += 1);
		if ((set = i == str.end()))
			this->*field = str;
	}
	return set;
}

bool	Contact::_SetFieldNum(std::string Contact::*field,
			const std::string &str) {
	bool	set;

	if (str.empty())
		set = false;
	else {
		std::string::const_iterator	i;
		for (i = str.begin(); i != str.end() && std::isdigit(*i); i += 1);
		if ((set = i == str.end()))
			this->*field = str;
	}
	return set;
}

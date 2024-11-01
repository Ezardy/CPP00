#ifndef EX01_CONTACT_HPP
# define EX01_CONTACT_HPP

# include <string>

class Contact {
public:
	Contact(void);
	~Contact(void);
	Contact(const Contact &contact);
	Contact(const std::string &firstName, const std::string &lastName,
			const std::string &nickName, const std::string &phoneNumber,
			const std::string &darkestSecret);
	Contact				&operator=(const Contact &contact);
	const std::string	&FirstName(void) const;
	const std::string	&LastName(void) const;
	const std::string	&NickName(void) const;
	const std::string	&PhoneNumber(void) const;
	const std::string	&DarkestSecret(void) const;
	bool				IsInvalid(void) const;
	bool				SetFirstName(const std::string &name);
	bool				SetLastName(const std::string &name);
	bool				SetNickName(const std::string &name);
	bool				SetPhoneNumber(const std::string &number);
	bool				SetDarkestSecret(const std::string &secret);
private:
	void				_Copy(const Contact &contact);
	bool				_SetFieldNonEmpty(std::string Contact::*field,
							const std::string &str);
	bool				_SetFieldAlpha(std::string Contact::*field,
							const std::string &str);
	bool				_SetFieldNum(std::string Contact::*field,
							const std::string &str);
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

#endif

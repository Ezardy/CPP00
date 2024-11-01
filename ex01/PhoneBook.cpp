#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _head(8), _tail(0) {}

PhoneBook::~PhoneBook(void) {

}

PhoneBook::PhoneBook(const PhoneBook &book) {
	_Copy(book);
}

PhoneBook	&PhoneBook::operator=(const PhoneBook &book) {
	_Copy(book);
	return *this;
}

bool	PhoneBook::AddContact(const Contact &contact) {
	bool	added = !contact.IsInvalid();
	if (added) {
		if (_head == 8) {
			_contacts[0] = contact;
			_head = 0;
		} else {
			_head = (_head + 1) % 8;
			_contacts[_head] = contact;
			if (_head == _tail)
				_tail = (_tail + 1) % 8;
		}
	}
	return added;
}

const Contact	&PhoneBook::GetContact(int index) const {
	const	Contact *contact;

	if (index > 7 || index < 0 || _Count()
		<= static_cast<unsigned short>(index))
		contact = &PhoneBook::invalidContact;
	else
		contact = _contacts + index;
	return *contact;
}

void	PhoneBook::_Copy(const PhoneBook &book) {
	if (_head != 8) {
		int	i;
		for (i = book._tail; i != book._head; i = (i + 1) % 8)
			_contacts[i] = book._contacts[i];
		_contacts[i] = book._contacts[i];
	}
	_tail = book._tail;
	_head = book._head;
}

unsigned short	PhoneBook::_Count(void) const {
	unsigned short	count;

	if (_head == 8)
		count = 0;
	else if (_head >= _tail)
		count = _head - _tail + 1;
	else
		count = 9 - _tail + _head;
	return count;
}

const Contact	PhoneBook::invalidContact;

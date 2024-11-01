cflags=-Wall -Wextra -Werror -std=c++98

all: phone_book

src=Contact PhoneBook main
obj=$(addsuffix .o, $(src))

debug: cflags+=-g
debug: all

clean:
	rm -f $(obj)

fclean: clean
	rm -f phone_book

re: fclean phone_book

phone_book: $(obj)
	c++ $(cflags) $(obj) -o $@

Contact.o: Contact.cpp Contact.hpp Makefile
	c++ $(cflags) -c $< -o $@

PhoneBook.o: PhoneBook.cpp PhoneBook.hpp Contact.hpp Makefile
	c++ $(cflags) -c $< -o $@

main.o: main.cpp PhoneBook.hpp Contact.hpp Makefile
	c++ $(cflags) -c $< -o $@
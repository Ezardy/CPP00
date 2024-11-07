cflags=-Wall -Wextra -Werror -std=c++98

all: tests

src=Account tests
obj=$(addsuffix .o, $(src))

tests: $(obj)
	c++ $(cflags) -o $@ $(obj)

tests.o: tests.cpp Account.hpp Makefile
	c++ $(cflags) -o $@ -c $<

Account.o: Account.cpp Account.hpp Makefile
	c++ $(cflags) -o $@ -c $<

clean:
	rm -f tests.o Account.o

fclean: clean
	rm -f tests

re: fclean tests
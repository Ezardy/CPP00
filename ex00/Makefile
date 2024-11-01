cflags=-Wall -Wextra -Werror -std=c++98

all: megaphone

megaphone: megaphone.o
	c++ $(cflags) $< -o $@

megaphone.o: megaphone.cpp Makefile
	c++ $(cflags) -c $< -o $@

re: fclean megaphone

clean:
	rm -f megaphone.o

fclean: clean
	rm -f megaphone
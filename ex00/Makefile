CFLAGS=-Wall -Wextra -Werror -std=c++98

all: megaphone

megaphone: megaphone.o
	c++ $(CFLAGS) $< -o $@

megaphone.o: megaphone.cpp Makefile
	c++ $(CFLAGS) -c $< -o $@

re: fclean megaphone

clean:
	rm -f megaphone.o

fclean: clean
	rm -f megaphone
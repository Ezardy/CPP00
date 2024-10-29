#include <cctype>
#include <iostream>

int	main(int argc, char *argv[])
{
	int	i;
	
	if (argc-- > 1)
	{
		argv += 1;
		while (argc--)
		{
			i = 0;
			while (argv[0][i])
				std::cout << static_cast<char>(std::toupper(argv[0][i++]));
			argv += 1;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

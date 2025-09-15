#include <unistd.h>

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2 || !*av[1])
		return (write(1, "x", 1), 0);
	int space;
	int word;
	word = 0;
	while (*av[1])
	{
		space = 0;
		while (*av[1] && ft_iswhitespace(*av[1]))
		{
			if (av[1][1] && !ft_iswhitespace(av[1][1]))
				space = 1;
			av[1]++;
		}
		if (space && word)
			write(1, "   ", 3);
		while (*av[1] && !ft_iswhitespace(*av[1]))
		{
			word = 1;
			write(1, av[1], 1);
			av[1]++;
		}
	}
	return (write(1, "\n", 1), 0);
}
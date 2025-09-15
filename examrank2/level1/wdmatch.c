#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (write(1, "\n", 1), 0);
	int i = 0;
	while (av[1][i] && *av[2])
	{
		if (av[1][i] == *av[2])
			i++;
		av[2]++;
	}
	if (i == ft_strlen(av[1]))
		write(1, "1", 1);
	else
		write(1, "0", 1);
		// ft_putstr(av[1]);
	return (write(1, "\n", 1), 0);
}
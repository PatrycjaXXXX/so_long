#include <unistd.h>

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_isalpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int is_last_letter_in_word(char *s)
{
	return (*(s+1) && ft_iswhitespace(*(s+1))
	|| !*(s+1));
}

char	tosmall(char c)
{
	return (c + (c >= 'A' && c <= 'Z') * 32);
}

char	tobig(char c)
{
	return (c + (c >= 'a' && c <= 'z') * (-32));
}

int main(int ac, char **av)
{
	int i = 1;
	while (i < ac)
	{
		while (*av[i])
		{
			if (ft_isalpha(*av[i]))
			{
				if (is_last_letter_in_word(av[i]))
					ft_putchar(tobig(*av[i]));
				else
					ft_putchar(tosmall(*av[i]));
			}
			else
				ft_putchar(*av[i]);
			av[i]++;
		}
		i++;
		ft_putchar('\n');
	}
	if (ac == 1)
		ft_putchar('\n');
	return (0);
}


#include <unistd.h>

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_atoi(char *s)
{
	int i = 0;
	int sign = 1;

	if (!s || !*s)
		return (0);
	while (ft_iswhitespace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		i = i * 10 + *s - '0';
		s++;
	}
	return (sign * i);
}

void	ft_puthex(unsigned int i)
{
	char	digit;
	char	*hex = "0123456789abcdef";

	if (i >= 16)
		ft_puthex(i / 16);
	digit = hex[i % 16];
	write (1, &digit, 1);
}

int main (int ac, char **av)
{
	if (ac != 2)
		return(write(1, "\n", 1), 0);
	int nb = ft_atoi(av[1]);
	if (nb < 0)
		return(write(1, "\n", 1), 0);
	ft_puthex((unsigned int)nb);
	return(write(1, "\n", 1), 0);
}
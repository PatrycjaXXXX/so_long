
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

int ft_isprime(int n)
{
	if (n < 2)
		return (0);
	if (n == 2)
		return 1;
	if (n % 2 == 0)
		return (0);
	int i = 3;
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

void	ft_putnbr(int i)
{
	char	digit;

	if (i == -2147483647)
		write(1, "-2147483647", 9);
	if (i < 0)
	{
		write (1, "-", 1);
		i = -i;
	}
	if (i >= 10)
		ft_putnbr(i / 10);
	digit = i % 10 + '0';
	write (1, &digit, 1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "0\n", 2), 0);
	int nb = ft_atoi(av[1]);
	if (nb <= 1)
		return (write(1, "0\n", 2), 0);
	int sum = 0;
	int i = 0;
	while (i <= nb)
	{
		if (ft_isprime(i))
			sum += i;
		i++;
	}
	ft_putnbr(sum);
	return (write(1, "\n", 1), 0);
}
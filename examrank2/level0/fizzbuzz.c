/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 06:38:48 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 06:54:58 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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


int main(void)
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0)
			ft_putstr("fizz");
		if (i % 5 == 0)
			ft_putstr("buzz");
		if (i % 3 != 0 && i % 5 != 0)
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}

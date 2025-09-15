/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:23:05 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/15 13:51:19 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int ft_isprime(unsigned int n)
{
	if (n < 2)
		return (0);
	if (n == 2)
		return (1);
	if (n % 2 == 0)
		return (0);
	unsigned int i = 3;
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 2 || atoi(av[1]) <= 0)
		return (printf("\n"), 0);
	unsigned int n = (unsigned int)atoi(av[1]);
	if (n == 1)
		return (printf("1\n"), 0);
	if (ft_isprime(n))
		return (printf("%u\n", n), 0);
	unsigned int i = 2;
	while (n > 1)
	{
		while (!ft_isprime(i))
			i++;
		while (n % i == 0)
		{
			printf("%u", i);
			n = n / i;
			if (n > 1)
				printf("*");
		}
		i++;
	}
	return (printf("\n"), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:14:45 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 12:40:24 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	
	if (ac ==2)
	{
		while (*av[1])
		{
			if (*av[1] >= 'A' && *av[1] <= 'Z')
			{
				ft_putchar("_");
				ft_putchr(*av[1] + 32);
			}
			else
				ft_putchar(*av[1]);
			av[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 07:45:18 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 09:05:40 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	int rot = 1;
	if (ac ==2)
	{
		while (*av[1])
		{
			if (*av[1] >= 'a' && *av[1] <= 'z')
				ft_putchar('a' + (*av[1] - 'a' + rot) % 26);
			else if (*av[1] >= 'A' && *av[1] <= 'Z')
				ft_putchar('A' + (*av[1] - 'A' + rot) % 26);
			else
				ft_putchar(*av[1]);
			av[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

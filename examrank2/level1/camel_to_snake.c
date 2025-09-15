/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:41:07 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/15 06:23:15 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

// int main(int ac, char **av)
// {
	
// 	if (ac ==2)
// 	{
// 		while (*av[1])
// 		{
// 			if (*av[1] >= 'A' && *av[1] <= 'Z')
// 			{
// 				ft_putchar('_');
// 				ft_putchar(*av[1] + 32);
// 			}
// 			else
// 				ft_putchar(*av[1]);
// 			av[1]++;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }

int main(int ac, char **av)
{
	
	if (ac ==2)
	{
		while (*av[1])
		{
			if (*av[1] == '_')
			{
				av[1]++;
				ft_putchar(*av[1] - 32);
			}
			else
				ft_putchar(*av[1]);
			av[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
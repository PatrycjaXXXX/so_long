/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:50:52 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 12:02:16 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac ==2)
	{
		while (*av[1])
		{
			if (*av[1] >= 'a' && *av[1] <= 'z')
				ft_putchar('A' + *av[1] - 'a');
			else if (*av[1] >= 'A' && *av[1] <= 'Z')
				ft_putchar('a' + *av[1] - 'A');
			else
				ft_putchar(*av[1]);
			av[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:59:57 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 16:32:50 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int find_char(char *s, char c)
{
	int i = 0;
	
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (write(1, "\n", 1), 0);
	int	ascii_index[128];
	int i = 0;
	while (i < 128)
	{
		ascii_index[i] = 0;
		i++;
	}
	i = 0;
	while (av[1][i])
	{
		if (find_char(av[2], av[1][i]))
		{
			if (!ascii_index[(int)av[1][i]])
			{
				ascii_index[(int)av[1][i]] = 1;
				write(1, av[1] + i, 1);
			}
		}
		i++;
	}
	return (write(1, "\n", 1), 0);
}

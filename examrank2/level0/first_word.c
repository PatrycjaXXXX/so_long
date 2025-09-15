/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 06:03:46 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 06:36:35 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2 || !*av[1])
		return (write(1, "x", 1), 0);
	while (*av[1] && ft_iswhitespace(*av[1]))
		av[1]++;
	while (*av[1] && !ft_iswhitespace(*av[1]))
	{
		write(1, av[1], 1);
		av[1]++;
	}
	return (write(1, "\n", 1), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:41:06 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 16:50:34 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2 || !*av[1])
		return (write(1, "\n", 1), 0);
	int last = ft_strlen(av[1]) - 1;
	while (last >= 0 && ft_iswhitespace(av[1][last]))
		last--;
	if (last == -1)
		return (write(1, "\n", 1), 0);
	int i = 0;
	while (last >= 0 && !ft_iswhitespace(av[1][last]))
	{
		i++;
		last--;
	}
	while (i--)
	{
		last++;
		write(1, av[1] + last,1);
	}
	return (write(1, "\n", 1), 0);
}
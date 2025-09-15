/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 07:35:32 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 07:41:22 by psmolich         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	int	len = ft_strlen(av[1]);
	while (--len >= 0)
		write(1, &av[1][len], 1);
	return (write(1, "\n", 1), 0);
}

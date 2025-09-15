/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:39:18 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 15:57:16 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int len = ft_strlen(str);
	char temp;
	int i = 0;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = temp;
		len--;
		i++;
	}
	return (str);
}



int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	int	len = ft_strlen(av[1]);
	while (--len >= 0)
		write(1, &av[1][len], 1);
	char *line = ft_strrev(av[1]);
	printf("\n%s", line);
	write(1, "\n", 1);
}
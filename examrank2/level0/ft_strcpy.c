/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 06:56:56 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 07:18:25 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s1 -> dst
// s2 -> src

#include <stdlib.h>
#include <unistd.h>

void ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int main(int ac, char **av)
{
	if (ac == 1)
		return (1);
	char dst[100];
	ft_strcpy(dst, av[1]);
	ft_putstr(dst);
	write(1, "\n", 1);
}
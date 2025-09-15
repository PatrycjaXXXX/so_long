/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:07:09 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 11:47:21 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}


int main(int ac, char **av)
{
	if (ac != 4 || ft_strlen(av[2]) != 1 || ft_strlen(av[3]) != 1)
		return (write(1, "\n", 1), 0);
	int len = ft_strlen(av[2]);
	while (*av[1])
	{
		if (ft_strncmp(av[1], av[2], len) == 0)
		{
			ft_putstr(av[3]);
			av[1] += len;
		}
		ft_putchar(*av[1]);
		av[1]++;
	}
	return (write(1, "\n", 1), 0);
}

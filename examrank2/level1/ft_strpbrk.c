/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:13:32 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 15:37:27 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	pars_s2(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (pars_s2(s2, s1[i]))
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	printf("%s\n", ft_strpbrk(av[1], av[2]));
	printf("%s\n", strpbrk(av[1], av[2]));
}

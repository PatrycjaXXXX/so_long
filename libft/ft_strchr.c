/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:54:47 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/13 18:22:09 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	d;

	if (!s)
		return (NULL);
	d = (unsigned char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == d)
			return ((char *)(s + i));
		i++;
	}
	if (d == 0)
		return ((char *)(s + i));
	return (NULL);
}

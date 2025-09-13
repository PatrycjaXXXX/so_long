/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:55:09 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/13 17:33:14 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str[0] = '\0';
	ft_strlcat(str, s1, len);
	ft_strlcat(str, s2, len);
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
// 	char s[] = "Klawiatura";
// 	char s1[] = "Alex";
// 	char *a;
// 	char *b;

// 	a = ft_strjoin(s, s1);
// 	b = ft_strjoin(s1, s);
// 	printf("a: %s\nb: %s\n", a, b);
// 	free(a);
// 	free(b);	
// }
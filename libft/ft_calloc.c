/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:53:27 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/13 13:00:07 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			over;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	over = nmemb * size;
	if (nmemb != over / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
//If nmemb or size is 0, then calloc() returns a unique
//pointer value that can be successfully passed to free().

//If the multiplication of nmemb and size
//would result in integer overflow, then calloc() returns an error.  By
//contrast,  an integer overflow would not be detected in the following
//call to malloc(), with the result that an incorrectly sized block  of
//memory would be allocated: malloc(nmemb * size);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 07:21:01 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 07:32:44 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	char	*s;
	int		repeat;

	if (ac != 2)
		return (write(1, "\n", 1), 1);
	s = av[1];
	while (*s)
	{
		repeat = 1;
		if (*s >= 'a' && *s <= 'z')
			repeat += *s - 'a';
		if (*s >= 'A' && *s <= 'Z')
			repeat += *s - 'A';
		while (repeat--)
			write(1, s, 1);
		s++;
	}
	return (write(1, "\n", 1), 0);
}
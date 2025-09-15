/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:45:35 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/15 05:34:19 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// void	print_bits(unsigned char octet)
// {
// 	int i = 8;
// 	while (--i >= 0)
// 	{
// 		if (octet >> i & 1)
// 			write(1, "1", 1);
// 		else
// 			write(1, "0", 1);
// 	}
// }

// void	print_bits(unsigned char octet)
// {
// 	int i = 0;
// 	while (i < 8)
// 	{
// 		if (octet >> i & 1)
// 			write(1, "1", 1);
// 		else
// 			write(1, "0", 1);
// 		i++;
// 	}
// }

void	print_bits(unsigned char octet)
{
	int i = 4;
	while (i--)
	{
		if (octet >> i & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	i = 8;
	while (i-- > 4)
	{
		if (octet >> i & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

int main(void)
{
	print_bits(65);
}
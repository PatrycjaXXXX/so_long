/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:50:46 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/14 13:00:40 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int main(int ac, char **av)
{
	int a;
	int b;

	if (ac != 4)
		return (printf("\n"), 0);
	a = atoi(av[1]);
	b = atoi(av[3]);
	if (*av[2] == '+')
		printf("%i", a + b);
	else if (*av[2] == '-')
		printf("%i", a - b);
	else if (*av[2] == '*')
		printf("%i", a * b);
	else if (*av[2] == '/')
		printf("%i", a / b);
	else if (*av[2] == '%')
		printf("%i", a % b);
	return (printf("\n"), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:44:40 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/08 05:24:15 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <unistd.h>

int	ft_move(char *move, t_list **a, t_list **b)
{
	ft_printf("%s", move);
	return (apply_instr(move, a, b));
}

static void	des_to_as(t_list **a, t_list **b, int size_a)
{
	int	moves;

	if (size_a == 2)
	{
		ft_move("sa\n", a, b);
		return ;
	}
	moves = size_a - 3;
	while (moves--)
	{
		ft_move("rra\n", a, b);
		ft_move("pb\n", a, b);
	}
	ft_move("ra\n", a, b);
	ft_move("sa\n", a, b);
	while (*b)
		ft_move("pa\n", a, b);
}

static int	ft_sort(t_list **a, t_list **b)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	if (ft_lstissorted_des(*a) == SUCCESS)
		des_to_as(a, b, size_a);
	else if (size_a <= 10)
		ft_selectionsort(a, b, size_a);
	else
		ft_longest_increasing_subsequence_sort(a, b);
	return (ft_lstissorted_as(*a));
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (FAIL);
	a = NULL;
	if (record_arg(ac, av, &a) == FAIL)
		return (ft_lstfree(&a), write(2, "Error\n", 6), FAIL);
	if (ft_lstissorted_as(a) == SUCCESS)
		return (ft_lstfree(&a), 0);
	b = NULL;
	if (ft_sort(&a, &b) == FAIL)
		return (ft_lstfree(&a), ft_lstfree(&b),
			write(2, "Error\n", 6), FAIL);
	ft_lstfree(&a);
	ft_lstfree(&b);
	return (0);
}
